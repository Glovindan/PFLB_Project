Action()
{
	lr_start_transaction("UC01_Login");
		web_set_sockets_option("SSL_VERSION", "AUTO");
	
		web_set_user("Glovindan", 
			lr_unmask("6390b3c47ee5dd2865696c52df4df6e0"), 
			"advantageonlineshopping.com:443");
	
		web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=advantageonlineshopping.com");
	
		web_url("advantageonlineshopping.com", 
			"URL={host}/", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			EXTRARES, 
			"Url=/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.eot?", ENDITEM, 
			"Url=/main.min.js", ENDITEM, 
			"Url=/css/fonts/roboto_light_macroman/Roboto-Light-webfont.eot?", ENDITEM, 
			"Url=/css/images/logo.png", ENDITEM, 
			"Url=/css/fonts/roboto_medium_macroman/Roboto-Medium-webfont.eot?", ENDITEM, 
			"Url=/css/images/closeDark.png", ENDITEM, 
			"Url=/services.properties", ENDITEM, 
			"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.eot?", ENDITEM, 
			"Url=/css/images/FacebookLogo.png", ENDITEM, 
			"Url=/css/images/Special-offer.jpg", ENDITEM, 
			"Url=/css/images/GoUp.png", ENDITEM, 
			"Url=/css/images/facebook.png", ENDITEM, 
			"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.eot?", ENDITEM, 
			"Url=/css/images/Banner2.jpg", ENDITEM, 
			"Url=/css/images/Banner1.jpg", ENDITEM, 
			"Url=/css/images/Banner3.jpg", ENDITEM, 
			"Url=/css/images/Popular-item3.jpg", ENDITEM, 
			"Url=/css/images/Popular-item2.jpg", ENDITEM, 
			"Url=/css/images/Popular-item1.jpg", ENDITEM, 
			"Url=/css/images/arrow_right.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=laptops", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=tablets", ENDITEM, 
			"Url=/css/images/linkedin.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=mice", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=headphones", ENDITEM, 
			"Url=/css/images/twitter.png", ENDITEM, 
			"Url=/css/images/Filter.png", ENDITEM, 
			"Url=/css/images/category_banner_3.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=3100", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=3300", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=3200", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=3301", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=3303", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=3302", ENDITEM, 
			LAST);
	
		web_url("ALL", 
			"URL={host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t2.inf", 
			"Mode=HTML", 
			LAST);
	
		web_add_header("SOAPAction", 
			"com.advantage.online.store.accountserviceGetAccountConfigurationRequest");
	
		web_add_header("X-Requested-With", 
			"XMLHttpRequest");
	
		web_custom_request("GetAccountConfigurationRequest", 
			"URL={host}/accountservice/ws/GetAccountConfigurationRequest", 
			"Method=POST", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/xml", 
			"Referer={host}/", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			"EncType=text/xml; charset=UTF-8", 
			"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
			LAST);
		
		web_url("categories", 
			"URL={host}/catalog/api/v1/categories", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			LAST);
	
		web_add_cookie("_ga=GA1.2.1596872114.1670427346; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("_gid=GA1.2.1902292005.1670427346; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("_gat=1; DOMAIN=advantageonlineshopping.com");
	
		web_url("search", 
			"URL={host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			LAST);
	
		web_url("popularProducts.json", 
			"URL={host}/app/tempFiles/popularProducts.json", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t6.inf", 
			"Mode=HTML", 
			LAST);
	
		web_url("home-page.html", 
			"URL={host}/app/views/home-page.html", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer={host}/", 
			"Snapshot=t7.inf", 
			"Mode=HTML", 
			LAST);
		
		lr_start_transaction("Login");
			lr_start_transaction("UC01_TR01_Login");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLoginRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(13);
				
		//		*************************
		//		јвторизаци€, сохранение токена и id пользовател€
		//		*************************
				web_reg_save_param("token",
					"LB=<ns2:t_authorization>",
					"RB=</ns2:t_authorization>",
					LAST);
				
				web_reg_save_param("userId",
					"LB=<ns2:userId>",
					"RB=</ns2:userId>",
					LAST);
			
				web_custom_request("AccountLoginRequest", 
					"URL={host}/accountservice/ws/AccountLoginRequest", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/xml", 
					"Referer={host}/", 
					"Snapshot=t8.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{user}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
					LAST);
			
				web_set_sockets_option("INITIAL_AUTH", "BASIC");
			
				web_add_auto_header("Authorization:",
					"Basic {token}");
			
				web_url("384472445", 
					"URL={host}/order/api/v1/carts/{userId}", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t9.inf", 
					"Mode=HTML", 
					LAST);
			lr_end_transaction("UC01_TR01_Login",LR_AUTO);
		lr_end_transaction("Login", LR_AUTO);
	
		lr_start_transaction("Logout");
			lr_start_transaction("UC01_TR02_Exit");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLogoutRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				web_custom_request("AccountLogoutRequest", 
					"URL={host}/accountservice/ws/AccountLogoutRequest", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/xml", 
					"Referer={host}/", 
					"Snapshot=t17.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>{token}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
					LAST);
			lr_end_transaction("UC01_TR02_Exit",LR_AUTO);
		lr_end_transaction("Logout",LR_AUTO);
	lr_end_transaction("UC01_Login",LR_AUTO);
	return 0;
}
