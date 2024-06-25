package com.wzy.j2eelabs.lab5.controller;

import com.wzy.j2eelabs.lab5.pojo.Courier;
import com.wzy.j2eelabs.lab5.pojo.DeliveryOrder;
import com.wzy.j2eelabs.lab5.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;


import javax.servlet.http.HttpSession;
import java.util.List;

/**
 * 实现页面跳转，
 */
@Controller
public class UserController {
    @Autowired
    private UserService userService;

    @RequestMapping(value = "/index", method = RequestMethod.GET)
    public String index(HttpSession session, Model model){
        String courierId = (String) session.getAttribute("courierId");
        List<DeliveryOrder> orders = userService.selectByCourierId(courierId);
        //使用model方法将员工信息在request域中共享
        model.addAttribute("orders", orders);
        return "index";
    }

    @RequestMapping("/login")
    public String login(String courierId, String password,
                        HttpSession session, RedirectAttributes redirectAttributes) {
        // 调用服务层验证用户名和密码
        boolean isAuthenticated = userService.userMatch(courierId, password);

        if (isAuthenticated) {
            //将参数存储在HTTP会话（HttpSession）中，这样任何控制器都可以访问它们
            //这里我们要让index控制器访问
            session.setAttribute("courierId", courierId);
            // 登录成功，重定向到主页
            return "redirect:/index";
        } else {
            // 登录失败，重新转发到这个登录页面
            return "login";
        }
    }

    // 从这里传入了pojo参数
    @RequestMapping("/insert")
    public String insert(DeliveryOrder deliveryOrder, Model model){
        userService.insertDelivery(deliveryOrder);
        List<DeliveryOrder> list = userService.selectAll();
        //使用model方法将员工信息在request域中共享
        model.addAttribute("list", list);
        return "redirect:/index";
    }

    // 这里使用url传递参数，别忘了接收
    @RequestMapping("/delete/{trackingId}")
    public String deleteDelivery(String trackingId, Model model){
        int affectedRows = userService.deleteDelivery(trackingId);
        if(affectedRows > 0){
            return "redirect:/index";
        }else{
            return "noMatching";
        }

    }

    @RequestMapping("/update")
    public String update(DeliveryOrder deliveryOrder, Model model){
        int affectedRows = userService.updateDelivery(deliveryOrder);
        if(affectedRows > 0){
            return "redirect:/index";
        }else{
            return "noMatching";
        }

    }
}
