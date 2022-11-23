package com.htmlres.cn;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;


/**
 * 
 * @author Administrator
 *
 */


public class GetHtml {
	
	public static String GetHtml(String urlStr,String charset)
	{
		String str = "";
		try {
			
			URL url = new URL(urlStr);
			
			BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream(), "gbk"));
			String temp="";
			while((temp=reader.readLine())!=null)
			{
				System.out.println(temp);
			}
			str = temp;
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return str;
	}
	
	public static void main(String[] args) {
		
		GetHtml("http://www.jj20.com/bz/nxxz/shxz/25612.html", "gbk");
	}
}
