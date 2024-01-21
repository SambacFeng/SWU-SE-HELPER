package exp7.server;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class RequestReceiver implements Runnable{
	Socket socket;
	ChatServer server;
	public RequestReceiver(ChatServer server, Socket socket) {
		this.socket = socket;
		this.server = server;
	}

	@Override
	public void run() {
		try(InputStream is = socket.getInputStream();
				OutputStream os = socket.getOutputStream();
				Scanner input = new Scanner(is);
				PrintWriter output = new PrintWriter(os);){
			
			while(true) {
				if(input.hasNextLine()) {
					String message = input.nextLine();
					// 响应获取数据的请求，发送数据
					if(message.startsWith("get")) {
						output.println(server.getRecords());
						output.flush();
					}
					// 接受客户端消息数据
					if(message.startsWith("messages:")) {
						server.addRecords(message);
					}
				}
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
