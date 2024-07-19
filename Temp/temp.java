package com.template.flows;

import co.paralleluniverse.fibers.Suspendable;
import com.template.contracts.CBDCContract;
import com.template.states.CBDCState;
import net.corda.core.contracts.Command;
import net.corda.core.contracts.StateAndRef;
import net.corda.core.flows.*;
import net.corda.core.identity.Party;
import net.corda.core.node.services.Vault;
import net.corda.core.node.services.vault.QueryCriteria;
import net.corda.core.transactions.SignedTransaction;
import net.corda.core.transactions.TransactionBuilder;
import net.corda.core.utilities.ProgressTracker;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

@InitiatingFlow
@StartableByRPC
public class TransferToken extends FlowLogic<SignedTransaction> {

    private String tokenName;
    private int value;
    private Party newOwner;

    public TransferToken(String tokenName, int value, Party newOwner) {
        this.tokenName = tokenName;
        this.value = value;
        this.newOwner = newOwner;
    }

    // ProgressTracker steps...

    @Suspendable
    @Override
    public SignedTransaction call() throws FlowException {
        Party notary = getServiceHub().getNetworkMapCache().getNotaryIdentities().get(0);

        List<StateAndRef<CBDCState>> inputStates = findSuitableTokenStates();
        int totalInputValue = inputStates.stream().mapToInt(state -> state.getState().getData().getValue()).sum();
        int change = totalInputValue - this.value;

        TransactionBuilder txBuilder = new TransactionBuilder(notary);
        inputStates.forEach(txBuilder::addInputState);

        CBDCState transferOutputState = new CBDCState(tokenName, value, getOurIdentity(), newOwner);
        txBuilder.addOutputState(transferOutputState, CBDCContract.CID);
        Command<CBDCContract.Transfer> transferCommand = new Command<>(new CBDCContract.Transfer(),
                getOurIdentity().getOwningKey());
        txBuilder.addCommand(transferCommand);

        if (change > 0) {
            CBDCState changeOutputState = new CBDCState(tokenName, change, getOurIdentity(), getOurIdentity());
            txBuilder.addOutputState(changeOutputState, CBDCContract.CID);
        }

        // Sign the transaction
        SignedTransaction partiallySignedTx = getServiceHub().signInitialTransaction(txBuilder);

        // Sessions with other parties
        List<FlowSession> sessions = new ArrayList<>();
        for (StateAndRef<CBDCState> inputState : inputStates) {
            Party owner = inputState.getState().getData().getOwner();
            if (!owner.equals(getOurIdentity())
                    && !sessions.stream().anyMatch(s -> s.getCounterparty().equals(owner))) {
                sessions.add(initiateFlow(owner));
            }
        }
        if (!newOwner.equals(getOurIdentity())
                && !sessions.stream().anyMatch(s -> s.getCounterparty().equals(newOwner))) {
            sessions.add(initiateFlow(newOwner));
        }

        // Collect signatures
        SignedTransaction fullySignedTx = subFlow(new CollectSignaturesFlow(partiallySignedTx, sessions));

        // Finalize the transaction
        return subFlow(new FinalityFlow(fullySignedTx, sessions));
    }

    private List<StateAndRef<CBDCState>> findSuitableTokenStates() {
        // Implementation remains the same as previously detailed, adjusted for the
        // context
    }
}

/*------------------------------------------------------------------------------------------------ */

package com.template.contracts;

// Import statements remain unchanged

public class CBDCContract implements Contract {
    public static final String CID = "com.template.contracts.CBDCContract";

    @Override
    public void verify(@NotNull LedgerTransaction tx) {
        // Existing verification logic for Issue command remains unchanged

        if (commandType instanceof Transfer) {
            // Verify there are inputs and outputs in the transaction
            if (tx.getInputs().isEmpty())
                throw new IllegalArgumentException("Transfer transaction must have inputs.");
            if (tx.getOutputs().isEmpty())
                throw new IllegalArgumentException("Transfer transaction must have outputs.");

            // Verify the sum of input values equals the sum of output values, ensuring no
            // CBDC is created or destroyed
            int inputSum = tx.inputsOfType(CBDCState.class).stream().mapToInt(CBDCState::getValue).sum();
            int outputSum = tx.outputsOfType(CBDCState.class).stream().mapToInt(CBDCState::getValue).sum();
            if (inputSum != outputSum)
                throw new IllegalArgumentException("The sum of input values must equal the sum of output values.");

            // Additional checks can be added here, such as verifying the transaction
            // includes a Transfer command with the required signers
        }

        // Additional commandType checks (e.g., Issue) remain unchanged
    }

    public static class Transfer implements CommandData {
    }
}

/*--------------------------------------------------------------------------- */
// ... [imports] ...

@InitiatingFlow
@StartableByRPC
public class TransferToken extends FlowLogic<SignedTransaction> {
    // ... [attributes, constructors, progress tracker] ...

    @Suspendable
    @Override
    public SignedTransaction call() throws FlowException {
        // ... [setup notary, existing logic] ...

        List<StateAndRef<CBDCState>> inputStates = findSuitableTokenStates();
        int totalInputValue = inputStates.stream().mapToInt(state -> state.getState().getData().getValue()).sum();
        int change = totalInputValue - this.value;

        TransactionBuilder txBuilder = new TransactionBuilder(notary);
        inputStates.forEach(txBuilder::addInputState);

        CBDCState outputState = new CBDCState(tokenName, value, getOurIdentity(), newOwner);
        txBuilder.addOutputState(outputState, CBDCContract.CID);

        if (change > 0) {
            CBDCState changeOutputState = new CBDCState(tokenName, change, getOurIdentity(), getOurIdentity());
            txBuilder.addOutputState(changeOutputState, CBDCContract.CID);
        }

        Command<CBDCContract.Commands.Transfer> command = new Command<>(new CBDCContract.Commands.Transfer(),
                getOurIdentity().getOwningKey());
        txBuilder.addCommand(command);

        // Sign the transaction
        SignedTransaction partlySignedTx = getServiceHub().signInitialTransaction(txBuilder);

        // Collect signatures from all participants
        List<FlowSession> sessions = inputStates.stream()
                .map(state -> initiateFlow(state.getState().getData().getOwner()))
                .collect(Collectors.toList());

        SignedTransaction fullySignedTx = subFlow(new CollectSignaturesFlow(partlySignedTx, sessions));

        // Finalize the transaction
        return subFlow(new FinalityFlow(fullySignedTx, sessions));
    }

    // ... [helper methods] ...
}

    /*--------------------------------------------------------------------------------------------*/

    @Override
    public void verify(@NotNull LedgerTransaction tx) throws IllegalArgumentException {
        for (CommandWithParties<CommandData> command : tx.getCommands()) {
            CommandData commandType = command.getValue();

            if (commandType instanceof Issue) {
                verifyIssue(tx, command.getSigners());
            } else if (commandType instanceof Transfer) {
                verifyTransfer(tx, command.getSigners());
            } else {
                throw new IllegalArgumentException("Unrecognised command.");
            }
        }
    }

    private void verifyIssue(LedgerTransaction tx, List<PublicKey> signers) throws IllegalArgumentException {
        // Issue verification logic remains the same
    }

private void verifyTransfer(LedgerTransaction tx, List<PublicKey> signers) throws IllegalArgumentException {
    if (tx.getInputs().isEmpty()) throw new IllegalArgumentException("Transfer should have at least one input.");
    if (tx.getOutputs().isEmpty()) throw new IllegalArgumentException("Transfer should have at least one output.");

    int inputSum = tx.inputsOfType(CBDCState.class).stream().mapToInt(CBDCState::getValue).sum();
    int outputSum = tx.outputsOfType(CBDCState.class).stream().mapToInt(CBDCState::getValue).sum();
    if (inputSum != outputSum) throw new IllegalArgumentException("The sum of input values must equal the sum of output values.");

    tx.getOutputs().forEach(output -> {
        ContractState state = output.getData();
        if (!(state instanceof CBDCState)) throw new IllegalArgumentException("All outputs must be CBDCState.");
        CBDCState cbdcState = (CBDCState) state;
        if (!cbdcState.getTokenName().equals("CBDC") && !cbdcState.getTokenName().equals("Currency")) {
            throw new IllegalArgumentException("Token is not CBDC or Currency.");
        }
    });

    // Ensure all CBDCState outputs have a corresponding signer
    tx.getOutputs().stream().map(output -> (CBDCState) output.getData())
            .forEach(cbdcState -> {
                if (!signers.contains(cbdcState.getOwner().getOwningKey())) {
                    throw new IllegalArgumentException("All CBDCState owners must be signers.");
                }
            });
}
