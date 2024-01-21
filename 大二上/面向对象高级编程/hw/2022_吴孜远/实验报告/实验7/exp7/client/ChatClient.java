package exp7.client;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.Scanner;

import exp7.entity.ChatRecord;

public class ChatClient extends Socket{
	Scanner input;
	PrintWriter output;
	
	public void connect(String id, int port) {
		try {
			super.connect(new InetSocketAddress(id, port));
			input = new Scanner(this.getInputStream());
			output = new PrintWriter(this.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void sendChat(ChatRecord chat) {
		output.println("messages:" + chat.toString());
		output.flush();
	}
	
	public String get() {
		output.println("get\n");
		output.flush();
		StringBuilder text = new StringBuilder("");
		if(input.hasNextLine()) {
			String data = input.nextLine().trim();
			if(data.startsWith("messages:")) {
				if(data.length() > 9) {
					String[] messages = data.substring(9).split("&");
					for(String m : messages) {
						//System.out.println(m);
						String[] items = m.split("\t");
						text.append(items[0] + " " + items[1] + "\n" + items[2] + "\n");
					}
					
				}
			}
		}
		return text.toString();
	}
	
}
