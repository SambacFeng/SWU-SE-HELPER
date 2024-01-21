package exp1;

import java.util.Scanner;

public class Test2 {
	public static void main(String[] args) {
		try(Scanner input = new Scanner(System.in)){ //try异常处理机制
			while(true) {
				try {
					System.out.print("输入计算式，操作数与操作符用空格隔开：");
					if(input.hasNextLine()) {
						String s = input.nextLine();
						System.out.println("计算结果：" + calc(s));
					}
				}catch(Exception e) {
					System.out.println("异常类型：" + e.getMessage());
				}
			}
		}

	}
	
	public static double calc(String calcStr) throws Exception{
		String[] items = calcStr.split(" ");
		if(items.length != 3)
			throw new Exception("计算式不正确");
		double x;
		double y;
		try {
			x = Double.parseDouble(items[0]);
			y = Double.parseDouble(items[2]);
		}catch(Exception e) {
			throw new Exception("操作数格式错误");
		}
		switch(items[1]) {
			case "+": return x + y;
			case "-": return x - y;
			case "*": return x * y;
			case "/": return x / y;
			default: throw new Exception("未知的计算符");
		}
	}

}
