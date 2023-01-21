Action()
{
	lr_start_transaction("UC05_Remove");
		web_set_sockets_option("SSL_VERSION", "AUTO");
	
		/*web_set_user("{user}", 
			lr_unmask("63a98d7589138b3aa733fbfa"), 
			"advantageonlineshopping.com:443");*/
	
		web_add_cookie("_gid=GA1.2.90164077.1672054457; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("_ga=GA1.2.1351021203.1670609043; DOMAIN=advantageonlineshopping.com");
	
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
			"Url=/services.properties", ENDITEM, 
			"Url=/css/images/closeDark.png", ENDITEM, 
			"Url=/css/fonts/roboto_bold_macroman/Roboto-Bold-webfont.eot?", ENDITEM, 
			"Url=/css/images/FacebookLogo.png", ENDITEM, 
			"Url=/css/images/Special-offer.jpg", ENDITEM, 
			"Url=/css/images/facebook.png", ENDITEM, 
			"Url=/css/images/GoUp.png", ENDITEM, 
			"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.eot?", ENDITEM, 
			"Url=/css/images/Banner3.jpg", ENDITEM, 
			"Url=/css/images/Banner1.jpg", ENDITEM, 
			"Url=/css/images/Banner2.jpg", ENDITEM, 
			"Url=/css/images/Popular-item3.jpg", ENDITEM, 
			"Url=/css/images/Popular-item1.jpg", ENDITEM, 
			"Url=/css/images/Popular-item2.jpg", ENDITEM, 
			"Url=/css/images/arrow_right.png", ENDITEM, 
			"Url=/css/images/twitter.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=laptops", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=mice", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=tablets", ENDITEM, 
			"Url=/css/images/linkedin.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=headphones", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4700", ENDITEM, 
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
	
		web_url("search", 
			"URL={host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			LAST);
	
		web_add_cookie("_gat=1; DOMAIN=advantageonlineshopping.com");
	
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
			lr_start_transaction("UC05_T01_Login");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLoginRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(27);
			
				web_reg_save_param("token",
					"LB=t_authorization>",
					"RB=<",
					LAST);
			
				web_reg_save_param("user_id",
				"LB=userId>",
				"RB=<",
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
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{passwd}</loginPassword><loginUser>{user}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
					LAST);
			
				web_set_sockets_option("INITIAL_AUTH", "BASIC");
				
				web_add_auto_header("Authorization",
					"Basic {token}");
			
				web_reg_save_param_json(
					"ParamName=exist",
					"QueryString=$.productsInCart.*",
					"SelectAll=Yes",
					"NotFound=warning",
					SEARCH_FILTERS,
					LAST);	
					
				web_url("{user_id}", 
					"URL={host}/order/api/v1/carts/{user_id}", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t9.inf", 
					"Mode=HTML", 
					LAST);
			lr_end_transaction("UC05_T01_Login",LR_AUTO);
		lr_end_transaction("Login", LR_AUTO);
	
		lr_think_time(15);
		lr_start_transaction("Cart_open");
			lr_start_transaction("UC05_T02_Cart_open");
				web_url("shoppingCart.html", 
					"URL={host}/app/views/shoppingCart.html", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/html", 
					"Referer={host}/", 
					"Snapshot=t12.inf", 
					"Mode=HTML", 
					LAST);
			lr_end_transaction("UC05_T02_Cart_open",LR_AUTO);
		lr_end_transaction("Cart_open", LR_AUTO);
	
		lr_think_time(40);
		lr_start_transaction("Cart_product_remove");
			lr_start_transaction("UC05_T03_Cart_product_remove");
			 	if (atoi(lr_eval_string("{exist_count}")) > 0){
					lr_save_string(lr_paramarr_random("exist"), "exist_random");
				
					lr_eval_json(
						"Buffer={exist_random}",
					    "JsonObject=exist_json", 
				         LAST);
				
					lr_json_get_values(
						"JsonObject=exist_json",
				        "ValueParam=productId",
				        "QueryString=$..productId",
				        "SelectAll=No",
				         LAST);
					
					lr_json_get_values(
						"JsonObject=exist_json",
				        "ValueParam=colorId",
				        "QueryString=$..code",
				        "SelectAll=No",
				         LAST);
					
					web_custom_request("55CDD5", 
						"URL={host}/order/api/v1/carts/{user_id}/product/{productId}/color/{colorId}", 
						"Method=DELETE", 
						"TargetFrame=", 
						"Resource=0", 
						"RecContentType=application/json", 
						"Referer={host}/", 
						"Snapshot=t13.inf", 
						"Mode=HTML", 
						LAST);
				
				}
			lr_end_transaction("UC05_T03_Cart_product_remove",LR_AUTO);
		lr_end_transaction("Cart_product_remove", LR_AUTO);
		
		lr_start_transaction("Logout");
			lr_start_transaction("UC05_T04_Logout");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLogoutRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(23);
			
				web_custom_request("AccountLogoutRequest", 
					"URL={host}/accountservice/ws/AccountLogoutRequest", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/xml", 
					"Referer={host}/", 
					"Snapshot=t14.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{user_id}</loginUser><base64Token>Basic {token}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
					LAST);
			lr_end_transaction("UC05_T04_Logout",LR_AUTO);
		lr_end_transaction("Logout", LR_AUTO);
	lr_end_transaction("UC05_Remove", LR_AUTO);
	return 0;
}