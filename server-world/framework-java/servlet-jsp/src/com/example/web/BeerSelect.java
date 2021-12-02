package com.example.web;

import com.example.model.*;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

public class BeerSelect extends HttpServlet {
    public void doPost (HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        String c = request.getParameter("color");
        BeerExpert be = new BeerExpert();
        List result = be.getBrands(c);

        request.setAttribute("styles", result);

        // 为 JSP 实例化一个请求分派器
        RequestDispatcher view = request.getRequestDispatcher("result.jsp");
        // 使用请求分派器要求容器准备好 JSP 并向 JSP 发送请求和相应
        view.forward(request, response);
    }
}