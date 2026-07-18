# Import FastMCP
from pathlib import Path
import time

from fastmcp import Context, FastMCP

# 1. Initialize FastMCP server
mcp = FastMCP("test-server")

resources = {
    "one": "dgsddfbbrbtrbetrbnt",
    "two": "4g452gtwb4bg53bt5rbtrb",
    "three": "hg4gb5bg54b3b53b5rt",
}


# 3. Add a resource for serving .gz files with proper MIME type
# @mcp.resource("data://sample.txt.gz", mime_type="application/gzip")
# def get_sample_gz() -> bytes:
#     """Serve the sample.txt.gz file with correct MIME type."""
#     # with open("sample.txt.gz", "rb") as f:
#     #     return f.read()
#     file_path = Path("sample.txt.gz")

#     if not file_path.exists():
#         raise FileNotFoundError("File not found")

#     return file_path.read_bytes()  # raw binary


# 2. Add a tool using the decorator
@mcp.tool()
def add(a: int, b: int) -> int:
    """Adds two integer numbers together."""
    return a + b


@mcp.resource("data://docs", mime_type="application/json")
def get_doc_list():
    """Returns a list of available document keys."""
    return list(resources.keys())


@mcp.resource("data:docs/{doc}", mime_type="plain/text")
def get_doc_content(doc: str):
    """Returns the content of the specified document."""
    if doc not in resources:
        raise KeyError(f"Document '{doc}' not found")
    return resources[doc]


@mcp.tool()
def multiply(a: float, b: float) -> float:
    """Multiply two numbers."""
    return a * b


@mcp.tool()
async def generate_report(context: Context) -> str:
    """Multiply two numbers."""
    await context.info("Started")
    await context.report_progress(30, 100)
    time.sleep(10)

    await context.info("Almost completed")
    await context.report_progress(65, 100)
    time.sleep(10)

    await context.info("Started")
    await context.report_progress(100, 100)

    return "report generated , this a dummy report 2, test completed"


# 3. Run the server
if __name__ == "__main__":
    mcp.run(transport="streamable-http")
