<%--
  Created by IntelliJ IDEA.
  User: wuzir
  Date: 2024/5/28
  Time: 20:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<%-- JSP Comment --%>
<h1>Hello World!</h1>
    <%@ page import="java.time.LocalDate" %>
    <%@ page import="java.time.LocalTime" %>
<%-- 用java语法输出当前日期--%>
    <p>当前日期：<% out.println(LocalDate.now());%></p>
<%--    <%=: JSP表达式开始标签，用于将Java代码的结果输出到页面上  --%>
    <p>当前时间：<%=LocalTime.now().withNano(0) %></p>
</body>
</html>
