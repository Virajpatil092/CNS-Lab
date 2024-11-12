# server.py
import socket
import hashlib
import json

def sha1_hash(data):
    sha1 = hashlib.sha1()
    sha1.update(data.encode())
    return sha1.hexdigest()

user_db = {}

def handle_client_connection(client_socket):
    request = client_socket.recv(1024).decode()
    request_data = json.loads(request)
    
    action = request_data.get('action')
    username = request_data.get('username')
    password = request_data.get('password')
    
    if action == 'register':
        if username in user_db:
            response = {'status': 'failure', 'message': 'User already exists'}
        else:
            user_db[username] = sha1_hash(password)
            response = {'status': 'success', 'message': 'User registered successfully'}
    
    elif action == 'login':
        if username not in user_db:
            response = {'status': 'failure', 'message': 'User does not exist'}
        else:
            stored_password_hash = user_db[username]
            received_password_hash = sha1_hash(password)
            if received_password_hash == stored_password_hash:
                response = {'status': 'success', 'message': 'Login successful'}
            else:
                response = {'status': 'failure', 'message': 'Incorrect password'}
    
    client_socket.send(json.dumps(response).encode())
    client_socket.close()

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('0.0.0.0', 9999))
server_socket.listen(5)
print('Server listening on port 9999')

while True:
    client_sock, addr = server_socket.accept()
    print(f'Accepted connection from {addr}')
    handle_client_connection(client_sock)