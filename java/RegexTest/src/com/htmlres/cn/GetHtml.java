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
			
			BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream(), charset));
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
		String[] a= {"https://www.woyaogexing.com/tupian/dongman/2022/210937.html",
				"https://www.umei.cc/weimeitupian/yijingtupian/281447.htm"};
		GetHtml(a[1], "utf-8");
	}
}
