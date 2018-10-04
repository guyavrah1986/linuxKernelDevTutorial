# Simple HTTPS server for testing purposes in Python
This folder contains all the relevant code/files that are required to hold a simple HTTPS server in Python
by utilizing the SimpleHTTPServer module.

# Preperations:
1. The OpenSLL library installed on the machine.
2. Python 2.7 with the SimpleHTTPServer module.
3. One need to generate a self-signed certificate using openssl (for the HTTP server).This can be done by the following: 
	- Generating an RSA public/private-key pair: $openssl genrsa -out private.pem 2048
	- Generating a self-signed certificate: $openssl req -new -x509 -key private.pem -out cacert.pem -days 1095

# Repository structure (within the root folder):
1. build: 
2. globalIncludeDir: 
3. scripts:

# Main technologies used:
1. 

# Resources:
1. Usage in the OpenSSL library and tools on Ubuntu machine:https://help.ubuntu.com/community/OpenSSL	



