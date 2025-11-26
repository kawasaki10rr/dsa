import socket

host = '127.0.0.1'
port = 8500

lk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lk.bind((host, port))
lk.listen()

print("Server waiting...")

while True:
    client, address = lk.accept()
    response = client.recv(1024)

    if response:
        print("text received is:", response.decode())
        upper = response.decode().upper()
        print("text in uppercase:", upper)
        client.send(upper.encode())   # ✅ send back to client

    client.close()  # close this connection
