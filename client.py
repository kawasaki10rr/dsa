import socket

host = '127.0.0.1'
port = 8500

lk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lk.connect((host, port))

print("sending data from client")
lk.send("Hello from the client".encode())

response = lk.recv(1024)
print("From server:", response.decode())

lk.close()
