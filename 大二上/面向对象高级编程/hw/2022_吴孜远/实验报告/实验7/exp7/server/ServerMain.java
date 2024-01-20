package exp7.server;

import java.io.IOException;


public class ServerMain{
	public static void main(String[] args) {
		try (ChatServer server = new ChatServer(8189)) {
			server.start();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
}
