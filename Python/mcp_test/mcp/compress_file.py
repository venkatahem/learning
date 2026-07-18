import gzip

with open("sample.txt", "rb") as f_in:
    with gzip.open("sample.txt.gz", "wb") as f_out:
        f_out.write(f_in.read())
