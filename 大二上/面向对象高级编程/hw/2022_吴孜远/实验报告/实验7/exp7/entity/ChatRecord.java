package exp7.entity;

public class ChatRecord {
	private String name = "匿名";
	private String time;
	private String content;
	
	public ChatRecord(String name, String time, String content) {
		this.name = name;
		this.time = time;
		this.content = content;
	}
	
	public ChatRecord(String chatString) {
		String[] items = chatString.split("\t");
		setName(items[0]);
		setTime(items[1]);
		setContent(items[2]);
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getTime() {
		return time;
	}
	public void setTime(String time) {
		this.time = time;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	public String toString() {
		return name + "\t" + time + "\t" + content;
	} 
}
