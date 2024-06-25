<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: wuzir
  Date: 2024/5/30
  Time: 19:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<h1>代取快递列表</h1>
<table>
    <tr>
        <th>Id</th>
        <th>Courier Id</th>
        <th>Tracking Id</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Actions</th> <!-- 添加动作列 -->
    </tr>
    <c:forEach items="${orders}" var="deliveryOrder">
    <form action="/update" method="post">
    <tr>
        <td>${deliveryOrder.deliveryId}</td>
        <td>${deliveryOrder.courierId}</td>
        <td>${deliveryOrder.trackingId}</td>
        <td><input type="text" name="address" value="${deliveryOrder.address}"></td>
        <td><input type="text" name="phone" value="${deliveryOrder.phone}"></td>
        <!-- 隐藏字段用于更新操作 -->
        <td>
            <input type="hidden" name="deliveryId" value="${deliveryOrder.deliveryId}"/>
            <input type="hidden" name="courierId" value="${deliveryOrder.courierId}"/>
            <input type="hidden" name="trackingId" value="${deliveryOrder.trackingId}"/>

            <!-- 更新按钮 它将使用表单的默认 action 属性来确定提交的目标 URL-->
            <input type="submit" name="action" value="Update">
            <%--使用 formaction 属性允许每个按钮有自己的提交目标 URL，即使它们在同一个表单内。
                这是一种在客户端决定行为逻辑并根据用户的操作将表单提交到不同处理程序的方法。--%>
            <input type="submit" name="action" value="Delete"
                   formaction="/delete/${deliveryOrder.trackingId}">
        </td>

    </tr>
    </form>
    </c:forEach>
</table>

<h2>加入新的订单</h2>
    <table>
        <tr>
            <th>Courier Id</th>
            <th>Tracking Id</th>
            <th>Address</th>
            <th>Phone</th>
            <th>Actions</th> <!-- 添加动作列 -->
        </tr>


        <tr>
            <form action="/insert" method="post">
            <td><input type="text" name="courierId"></td>
            <td><input type="text" name="trackingId"></td>
            <td><input type="text" name="address"></td>
            <td><input type="text" name="phone"></td>
            <td><button type="submit">Insert</button></td>
            </form>
        </tr>

    </table>


</body>
</html>
