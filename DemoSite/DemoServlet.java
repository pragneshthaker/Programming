package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/** 
 * Servlet implementation class ServletDemo
 */
@WebServlet("/ServletDemo.java")
public class ServletDemo extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ServletDemo() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Hi From Served at: ").append(request.getContextPath());
		response.setContentType("text/html;charset=UTF-8");
		
	       PrintWriter out = response.getWriter();
	       
	       
	        boolean nameErrorFlag = false;
	        boolean usernameErrorFlag = false;
	        boolean newPasswordErrorFlag = false;
	        boolean confirmPasswordErrorFlag = false;
	        boolean phoneNumberErrorFlag = false;
	       
	       
	       
	       String name  = request.getParameter("txtName");
	       if(name.length()<3)
			{
			 System.out.println("The name must have at least 3 char");
				nameErrorFlag = true;
				return;
			}
			nameErrorFlag = !(name.matches("[a-zA-Z]+"));
			if(nameErrorFlag){
				System.out.println("Enter Valid Name");
				
			}
			
	       String userName = request.getParameter("txtUserName");
	       if(userName.length() < 5)
			{
				System.out.println("The name must have at least 5 char  :");
				usernameErrorFlag = true;
				//return;
			}	
			
			usernameErrorFlag = !(userName.matches("[a-zA-Z0-9]+"));
			
			if( usernameErrorFlag)
			{
			  System.out.println("User name can have small a-z capital A-Z and 0-9 digits:");
			  //return;
			}
	       
	       
	       String newPassword = request.getParameter("createPassword") ;
	       if( newPassword.length() < 8)
			{
				System.out.println("The password must have at least 8 char  :");
				newPasswordErrorFlag = true;
				//return;
			}
			 newPasswordErrorFlag = !(newPassword.matches("[a-zA-Z0-9]+"));
			
			if( newPasswordErrorFlag){
			
				System.out.println("Password can have small a-z capital A-Z and 0-9 digits only:");
				//return;
			}
	       
	       
	       String retypePassword =  request.getParameter("retypePassword") ;
	       confirmPasswordErrorFlag = (retypePassword.compareTo(newPassword) !=0);
	       if(confirmPasswordErrorFlag){
	    	   System.out.println("new passwod and confirm password must match");
	       }
	       
	       String phonNumber  =  request.getParameter("txtPhoneNumber") ;
	       
			phoneNumberErrorFlag = phonNumber.matches("d{10}");
			if(phoneNumberErrorFlag)
			{
				System.out.println("Please enter 10 digit Number only(exclude 0 prefex in std code");
				//return;
			}
			
			if( !(nameErrorFlag || usernameErrorFlag || newPasswordErrorFlag || 
					confirmPasswordErrorFlag || phoneNumberErrorFlag)  )
			{
				System.out.println("Enteries Submitted Successfully");
			}
			else
			{
				System.out.println("please check the enteries");
			}
			
			
		   phoneNumberErrorFlag = false;
		   
	       String emailId  = request.getParameter("emailId") ;
	       String dateOfBirth   = request.getParameter("dateOfBirth") ;
	       String selCourses = request.getParameter("selCourses") ;
	       String chkCourse  = request.getParameter("chkCourse");
	       String gender  = request.getParameter("gender");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.getWriter().append("Hi From Served at: ").append(request.getContextPath());
		response.setContentType("text/html;charset=UTF-8");
	       PrintWriter out = response.getWriter();
	       out.println("\n.......This is a message");
	       //request.getParameterValues("gender");
	       out.println(request.getParameterValues("sgender"));
	}

}
