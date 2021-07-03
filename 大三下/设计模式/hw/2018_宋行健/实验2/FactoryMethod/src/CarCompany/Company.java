package CarCompany;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Company{

    public static void main(String[] args){
        // 配置工厂信息
        Map<String, IFactory> factoryMap = new HashMap<String, IFactory>();
        factoryMap.put("A", new FactoryA());
        factoryMap.put("B", new FactoryB());

        // 车辆仓库
        List<Car> list = new ArrayList<Car>();

        // 输入订单，根据订单选择工厂进行生产
        try(Scanner input = new Scanner(new FileInputStream(new File("E:\\设计模式\\0_实验报告\\实验2\\FactoryMethod\\order.txt")))){
            while(input.hasNext()) {
                String typeToCreate = input.next();
                IFactory selectedFactory = factoryMap.get(typeToCreate);
                list.add(selectedFactory.createCar());
            }
        } catch(FileNotFoundException e){
            e.printStackTrace();
        }

        // 打印车辆信息
        for(Car c:list) {
            c.getInfo();
        }
    }
}