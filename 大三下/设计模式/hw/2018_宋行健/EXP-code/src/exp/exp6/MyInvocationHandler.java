package exp.exp6;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.util.Date;

public class MyInvocationHandler implements InvocationHandler {
    public MyInvocationHandler(Object obj) {
        super();
        this.obj = obj;
    }

    Object obj;    // 被代理的

    // 设计代理流程
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        Manager m = Manager.getInstance();  // 单例管理登录状态
        Object o = null;
        if (m.isLogin()) {
            o = method.invoke(obj, args);    // 调用 obj 对象的函数
            m.log(new Date(System.currentTimeMillis()).toString() + "\t完成操作：" + method.getName());  // 写日志
        } else {
            m.log(new Date(System.currentTimeMillis()).toString() + "\t没有权限操作：" + method.getName()); // 写日志
        }
        return o;
    }

}
