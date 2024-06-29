<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: wuzir
  Date: 2024/5/30
  Time: 19:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<h2>This is the result</h2>
<table>
    <tr>
        <th>Id</th>
        <th>Courier Id</th>
        <th>Tracking Id</th>
        <th>Address</th>
        <th>Phone</th>
    </tr>
    <c:forEach items="${orders}" var="deliveryOrder">
        <tr>
            <td>${deliveryOrder.deliveryId}</td>
            <td>${deliveryOrder.courierId}</td>
            <td>${deliveryOrder.trackingId}</td>
            <td>${deliveryOrder.address}</td>
            <td>${deliveryOrder.phone}</td>
        </tr>
    </c:forEach>
</table>
</body>
</html>
