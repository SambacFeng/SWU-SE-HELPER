package exp6.biz;

public interface Command {
	void execute(); // 单步执行
	boolean done(); // 判断是否已完成
}
