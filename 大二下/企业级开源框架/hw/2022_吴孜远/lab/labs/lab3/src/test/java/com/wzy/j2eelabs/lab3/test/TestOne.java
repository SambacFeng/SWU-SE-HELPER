package com.wzy.j2eelabs.lab3.test;

import com.wzy.j2eelabs.lab3.mapper.DeliveryOrderMapper;
import com.wzy.j2eelabs.lab3.pojo.DeliveryOrder;
import com.wzy.j2eelabs.lab3.utils.SqlSessionUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;


public class TestOne {
    @Test
    public void insertTest(){
        SqlSession sqlSession = SqlSessionUtil.getSqlSession();
        DeliveryOrderMapper mapper = sqlSession.getMapper(DeliveryOrderMapper.class);
        DeliveryOrder first = new DeliveryOrder(25,"10010",  "swu", "13333333333");
        DeliveryOrder second = new DeliveryOrder(20,"10086",  "swu", "12222222222");
        mapper.insertDelivery(first);
        mapper.insertDelivery(second);
        System.out.println(first.getAddress());
    }

    @Test
    public void selectTest(){
        SqlSession sqlSession = SqlSessionUtil.getSqlSession();
        DeliveryOrderMapper mapper = sqlSession.getMapper(DeliveryOrderMapper.class);
        List<DeliveryOrder> list = mapper.selectByTrackingId("10086");
        list.forEach(System.out::println);
    }
    @Test
    public void deleteTest(){
        SqlSession sqlSession = SqlSessionUtil.getSqlSession();
        DeliveryOrderMapper mapper = sqlSession.getMapper(DeliveryOrderMapper.class);
        mapper.deleteDelivery("10086");
    }
    @Test
    public void updateTest(){
        SqlSession sqlSession = SqlSessionUtil.getSqlSession();
        DeliveryOrderMapper mapper = sqlSession.getMapper(DeliveryOrderMapper.class);
        DeliveryOrder update = new DeliveryOrder(15,"10010",  "swu", "123456789");
        mapper.updateDelivery(update);
    }
}
