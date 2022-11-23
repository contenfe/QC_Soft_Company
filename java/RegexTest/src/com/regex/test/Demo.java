package com.regex.test;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Demo {
	
	public static boolean regex(String str, String regex) {
        Pattern p = Pattern.compile(regex);
        Matcher m = p.matcher(str);
        while (m.find()) {
            return true;
        }
        return false;
    }

	public static void main1(String[] args) {
		
		
		
		
		
		String s = "<b>M</b><p>abc</p><p id='jas' >asdfas</p><p> iasd</p><p>ÂÒ°¢ÈøµÂ</p><p id='jsd' >ÌØÊâ</p><p>²âÊÔ33</p>";
		String s1="123ad1fae5adjakdf126435sfg232";
		String regex = "<p>(.*)?</p>";
		String regex1="\\d{2,}";
		
		Pattern p = Pattern.compile(regex);
		//p.matcher(regex);
		Matcher m = p.matcher(s);
		//boolean bs =  Pattern.matches(regex, s); //p.matcher("<p id='jas' >asdfas</p><p> iasd</p><p>ÂÒ°¢ÈøµÂ</p><p id='jsd' >ÌØÊâ</p><p>²âÊÔ33</p>");
		
		boolean b = m.matches();
		
		int i=0;
		
		System.out.println(m.groupCount());
		
		while(i<m.groupCount())
		{
			//System.out.println(m.group(i));
			i++;
			
			
		}
		
		System.out.println(b);
				
		regex(s,regex);
	}

}
