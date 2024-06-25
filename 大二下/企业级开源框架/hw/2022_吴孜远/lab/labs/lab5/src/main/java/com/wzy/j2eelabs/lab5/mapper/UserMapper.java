package com.wzy.j2eelabs.lab5.mapper;

import com.wzy.j2eelabs.lab5.pojo.Courier;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface UserMapper {
    @Select("select * from users where courier_id=#{courierId} and password=#{password}")
    List<Courier> userMatch(@Param("courierId") String courierId,
                            @Param("password")String password);
}
