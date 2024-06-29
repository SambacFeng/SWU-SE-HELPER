<%--
  Created by IntelliJ IDEA.
  User: wuzir
  Date: 2024/5/31
  Time: 22:15
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<form action="/login" method="POST">
    <div>
        <label for="courierId">courier id:</label>
        <input type="text" id="courierId" name="courierId" required>
    </div>
    <div>
        <label for="password">password:</label>
        <input type="password" id="password" name="password" required>
    </div>
    <div>
        <button type="submit">登录</button>
    </div>
</form>
</body>
</html>
