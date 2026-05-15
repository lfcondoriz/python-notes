def zip_compress(data):
    print(f"ZIP compressing {data}")

def rar_compress(data):
    print(f"RAR compressing {data}")

def compress(data, strategy):
    print("starting compression")
    result = strategy(data)
    print("done")
    return result

compress("file.txt", zip_compress)