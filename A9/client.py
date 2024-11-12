# client.py
import socket
import json

def send_request(action, username, password):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('127.0.0.1', 9999))
    
    request_data = {
        'action': action,
        'username': username,
        'password': password
    }
    
    client_socket.send(json.dumps(request_data).encode())
    response = client_socket.recv(1024).decode()
    response_data = json.loads(response)
    
    print(f'Server response: {response_data}')
    client_socket.close()

# Example usage
action = input("Enter action (register/login): ").strip()
username = input("Enter username: ").strip()
password = input("Enter password: ").strip()

send_request(action, username, password)