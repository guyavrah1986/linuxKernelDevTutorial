'''
import BaseHTTPServer, SimpleHTTPServer
import ssl

port = 8000    

httpd = BaseHTTPServer.HTTPServer(('', port), SimpleHTTPServer.SimpleHTTPRequestHandler)
httpd.socket = ssl.wrap_socket (httpd.socket, certfile="localhost.pem", keyfile="private.pem", server_side=True)
print "HTTPS server about to start at port:" , port
httpd.serve_forever()
'''
# =========================================================================================================================

import BaseHTTPServer, SimpleHTTPServer
import ssl
import sys

####################
# Global Variables #
####################


##########
# Consts #
##########

DEFAULT_PORT = 8080
DEFAULT_CERT_FILE = "localhost.pem"
DEFAULT_KEY_FILE = "private.pem"

###########
# Classes #
###########

class MyHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
    def handle_one_request(self):
        print(self.client_address[0])
        return SimpleHTTPServer.SimpleHTTPRequestHandler.handle_one_request(self)


#############
# Functions #
#############

def main():
	#Handler = SimpleHTTPServer.SimpleHTTPRequestHandler
    	try:
        	port = int(sys.argv[1])
    	except:
        	port = DEFAULT_PORT 
		certfile = DEFAULT_CERT_FILE
		keyfile = DEFAULT_KEY_FILE

	httpd = BaseHTTPServer.HTTPServer(('', port), MyHandler)
	httpd.socket = ssl.wrap_socket (httpd.socket, certfile=DEFAULT_CERT_FILE, keyfile=DEFAULT_KEY_FILE, server_side=True)

    	print "main - about to start HTTPS server at port %s/tcp ..." % port
    	httpd.serve_forever()

##############
# Enry Point #
##############

if __name__ == "__main__":
	sys.exit(main())
