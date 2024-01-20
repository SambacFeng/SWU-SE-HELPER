package exp7.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

import exp7.entity.ChatRecord;

public class ChatServer extends ServerSocket {
	List<ChatRecord> messageCache = new ArrayList<ChatRecord>();

	public ChatServer(int port) throws IOException {
		super(port);
	}
	
	public void start() {
		int i = 1;
		while(true) {
			try {
				Socket incoming = this.accept();
				System.out.printf("第%d个客户端\n", i++);
				Runnable receiver = new RequestReceiver(this, incoming);
				Thread t = new Thread(receiver);
				t.start();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	public String getRecords() {
		StringBuilder str = new StringBuilder();
		for(int i = 0; i < messageCache.size(); i++) {
			if(str.length() != 0) {
				str.append("&");
			}
			str.append(messageCache.get(i).toString());
		}
		str.insert(0, "messages:");
		return str.toString();
	}
	
	public void addRecords(String data){
		String[] chats = data.substring(9).split("&");
		for(String chat : chats) {
			messageCache.add(new ChatRecord(chat));
		}
	}
	
	public void stop() {
		this.stop();
	}
}
