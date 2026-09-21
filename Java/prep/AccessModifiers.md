public class AccessModifiers {
    
}

`public`
    - can be accessed any where, class, subclass, subclass(different package), different package
`private`
    - can be accessed only in same class
`projected`
    - - can be accessed in same class, subclass, subclass(different package), but not different package
`default`
    - can be accessed in class, subclass, but not in subclass(different package), and different package

## Java Access Modifiers

| Access Modifier | Same Class | Same Package | Subclass (Different Package) | Different Package (Non-Subclass) |
|---|---:|---:|---:|---:|
| `private` | ✅ | ❌ | ❌ | ❌ |
| *(default)* / package-private | ✅ | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ✅* | ❌ |
| `public` | ✅ | ✅ | ✅ | ✅ |

### Restrictions

| Access Modifier | Restrictions |
|---|---|
| `private` | Accessible **only within the class** where it is declared. |
| *(default)* / package-private | Accessible **only within the same package**. No keyword is used. |
| `protected` | Accessible within the **same package**. Outside the package, accessible only through **inheritance/subclass access**. |
| `public` | Accessible **everywhere**, as long as the containing class/member is accessible. |

> **Note:** `protected` access from a different package has an important restriction: a subclass can access the protected member through **inheritance**, but not through an arbitrary instance of the superclass.

### Quick Order

```text
private < default < protected < public
  least accessible        most accessible
```

