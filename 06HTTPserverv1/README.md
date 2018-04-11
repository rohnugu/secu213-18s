# Task 06: Make a HTTP server

Before doing this task, please visit the following site:
https://www.joinc.co.kr/w/Site/Network_Programing/AdvancedComm/HTTP

 - Write a code of a simple HTTP server which filename is HTTPserver_201727####.c
 - Your server should response the following message

![A Sample HTTP Response Message](https://www.ntu.edu.sg/home/ehchua/programming/webprogramming/images/HTTP_ResponseMessageExample.png)

 - Your client should parse the status line, response headers, and the message body.

```html
HTTP/1.1 200 OK
Date: Thu, 12 Apr 2018 14:00:00 GMT
Server: SECU213/2018 Spring
Vary: Accept-Encoding
Content-Length: 289
Content-Type: text/html; charset=UTF-8


<!DOCTYPE html>
	<html>
		<head>
			<title>Hello, World!</title>
		</head>
	<body>
		<h1>Hello, World!</h1>
	</body>
</html>

```
