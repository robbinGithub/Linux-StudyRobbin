
package com.company;


import java.io.OutputStream;
import java.net.Socket;

public class Main {
    public static void main(String args[]) throws Exception {
        // 要连接的服务端IP地址和端口
        String host = "106.12.157.253";
        int port = 5020;
        // 与服务端建立连接
        Socket socket = new Socket(host, port);
        // 建立连接后获得输出流
        OutputStream outputStream = socket.getOutputStream();
        String message="你好  yiwangzhibujian";
        socket.getOutputStream().write(message.getBytes("UTF-8"));
        outputStream.close();
        socket.close();
    }
}d.dd/Tutorial 100
