# Task 04: Make a HTTP client

Before doing this task, please visit the following site:
https://www.joinc.co.kr/w/Site/Network_Programing/AdvancedComm/HTTP

## Sub-task 1: Make a simple HTTP 0.9 client
 - Write a code of a simple HTTP client which filename is HTTP0.9client_201727####.c
 - Your HTTP client should read arguments from command line
 - Assume that the second argument follows the format: netlab.korea.ac.kr/index.htm
 - The string "netlab.korea.ac.kr" should be converted to the corresponding IPv4 address in order to make a connection to the server.
 - After establishing the connection, the client send the following sentence "GET /index.htm\r\n\r\n".
 - The client should print the response.
 - Build and test your code by typing into the command line:  
$ ./HTTP0.9client netlab.korea.ac.kr/index.htm  
$ ./HTTP0.9client fnc.korea.ac.kr/index.htm

## Sub-task 2: Make a simple HTTP 1.1 client
 - Write a code of a simple HTTP 1.1 client which filename is HTTP1.1client_201727####.c
 - After establishing the connection, the client send the following sentence
"GET /index.htm HTTP/1.1\r\nHost: netlab.korea.ac.kr\r\n\r\n".
 - Note that the format is as follows:
![A Sample HTTP Request Message](https://www.ntu.edu.sg/home/ehchua/programming/webprogramming/images/HTTP_RequestMessageExample.png)
 - Build and test your code by typing into the command line:  
$ ./HTTP1.1client netlab.korea.ac.kr/index.htm  
$ ./HTTP1.1client fnc.korea.ac.kr/index.htm

## Sub-task 3: Parse the HTTP response message
 - When your client sends the above sentence in Sub-task 2 to a server, the server replies a HTTP response message to your client. The format is as follows:

![A Sample HTTP Response Message](https://www.ntu.edu.sg/home/ehchua/programming/webprogramming/images/HTTP_ResponseMessageExample.png)

 - Your client should parse the status line, response headers, and the message body.

```html
HTTP/1.1 200 OK
Date: Wed, 04 Apr 2018 19:52:25 GMT
Server: Apache/2.4.7
X-Powered-By: PHP/5.5.9-1ubuntu4.22
Vary: Accept-Encoding
Content-Length: 289
Content-Type: text/html; charset=UTF-8


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
                                         <html>
                                               <head><title>Network Research Lab., Korea University</title>
                           <meta http-equiv="Refresh" Content="0;url=netlab/mainFrame.htm">
           </head>

                  <body>
                        </body>

                               </html>

```
