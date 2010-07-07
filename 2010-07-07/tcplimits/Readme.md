# Testing Windows Tcp connection limits

## About

About a year ago, I wrote a very simple Comet server using ASP.NET. I was hoping to get a massive number of clients connected by using the .NET thread pool and keeping client state using wait handles. However I was surprised that I could only get 16,000 active connections before things started to fail. I figured that there was some limitation to the way that the .NET framework handled sockets.

Later on I was doing some simple Tcp programming using Winsock in C, so I hacked together this quick test application to create lots of Tcp connections to see where the true limit was for Windows.

## Results
on Vista, even when using Winsock directly in C things topped out at 16,000 connections just like they did on .NET.
we have attempts at using c for tcpip programming here

dan newcome dec 2009
update
create a client to test how many connections we could possibly do on windows..
on vista topped out at 16k just like on .net when we tried this.
