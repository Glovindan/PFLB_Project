Action()
{
	lr_start_transaction("UC04_Add_to_cart");
		web_set_sockets_option("SSL_VERSION", "AUTO");
		
		web_add_cookie("_gid=GA1.2.1319780161.1672294661; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("_ga=GA1.2.1351021203.1670609043; DOMAIN=advantageonlineshopping.com");
	
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
			"Url=/css/images/facebook.png", ENDITEM, 
			"Url=/css/images/GoUp.png", ENDITEM, 
			"Url=/css/fonts/roboto_thin_macroman/Roboto-Thin-webfont.eot?", ENDITEM, 
			"Url=/css/images/Banner1.jpg", ENDITEM, 
			"Url=/css/images/Banner2.jpg", ENDITEM, 
			"Url=/css/images/Banner3.jpg", ENDITEM, 
			"Url=/css/images/Popular-item3.jpg", ENDITEM, 
			"Url=/css/images/Popular-item1.jpg", ENDITEM, 
			"Url=/css/images/Popular-item2.jpg", ENDITEM, 
			"Url=/css/images/twitter.png", ENDITEM, 
			"Url=/css/images/arrow_right.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=tablets", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
			"Url=/css/images/linkedin.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=laptops", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=mice", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=headphones", ENDITEM, 
			"Url=/css/images/Filter.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4200", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4500", ENDITEM, 
			"Url=/css/images/category_banner_4.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4700", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4400", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4300", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4600", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4100", ENDITEM, 
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
	
		web_reg_save_param_json(
			"ParamName=category_all",
			"QueryString=$..categoryId",
			"SelectAll=Yes",
			SEARCH_FILTERS,
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
	
		lr_save_string(lr_paramarr_random("category_all"), "category_random");
		
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
	
		web_add_cookie("_gat=1; DOMAIN=advantageonlineshopping.com");
	
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
			lr_start_transaction("UC04_T01_Login");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLoginRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(25);
			
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
			
				web_add_auto_header("Authorization:", "Basic {token}");
				
				web_reg_save_param_json(
					"ParamName=session_id",
					"QueryString=$.sessionId",
					"SelectAll=No",
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
			lr_end_transaction("UC04_T01_Login",LR_AUTO);
		lr_end_transaction("Login", LR_AUTO);
	
		lr_think_time(32);
		lr_start_transaction("Category_select");
			lr_start_transaction("UC04_T02_Category_select");
				web_reg_save_param_json(
					"ParamName=product_all",
					"QueryString=$..products[?(@.productStatus == \"Active\")].productId",
					"SelectAll=Yes",
					SEARCH_FILTERS,
					LAST);
			
				
				web_url("products", 
					"URL={host}/catalog/api/v1/categories/{category_random}/products", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t10.inf", 
					"Mode=HTML", 
					LAST);
			
				lr_save_string(lr_paramarr_random("product_all"), "product_random");
				
				web_url("attributes", 
					"URL={host}/catalog/api/v1/categories/attributes", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t11.inf", 
					"Mode=HTML", 
					LAST);
			
				web_url("category-page.html", 
					"URL={host}/app/views/category-page.html", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/html", 
					"Referer={host}/", 
					"Snapshot=t12.inf", 
					"Mode=HTML", 
					LAST);
			lr_end_transaction("UC04_T02_Category_select",LR_AUTO);
		lr_end_transaction("Category_select", LR_AUTO);
	
		lr_think_time(30);
		lr_start_transaction("Product_select");
			lr_start_transaction("UC04_T03_Product_select");
				web_reg_save_param_json(
					"ParamName=color_all",
					"QueryString=$..code",
					"SelectAll=Yes",
					SEARCH_FILTERS,
					LAST);
				
				web_url("25", 
					"URL={host}/catalog/api/v1/products/{product_random}", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t13.inf", 
					"Mode=HTML", 
					LAST);
			
				lr_save_string(lr_paramarr_random("color_all"), "color_random");
				
				web_url("all_data", 
					"URL={host}/catalog/api/v1/categories/all_data", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t14.inf", 
					"Mode=HTML", 
					LAST);
			
				web_url("product-page.html", 
					"URL={host}/app/views/product-page.html", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/html", 
					"Referer={host}/", 
					"Snapshot=t16.inf", 
					"Mode=HTML", 
					LAST);
			lr_end_transaction("UC04_T03_Product_select",LR_AUTO);
		lr_end_transaction("Product_select", LR_AUTO);
		
		lr_start_transaction("Cart_add");
			lr_start_transaction("UC04_T04_Cart_add");
				web_submit_data("55CDD5", 
					"Action={host}/order/api/v1/carts/{user_id}/product/{product_random}/color/{color_random}?quantity=1", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t17.inf", 
					"Mode=HTML", 
					ITEMDATA, 
					"Name=sessionId", "Value={session_id}", ENDITEM, 
					LAST);
			lr_end_transaction("UC04_T04_Cart_add",LR_AUTO);
		lr_end_transaction("Cart_add", LR_AUTO);
		
		lr_start_transaction("Logout");
			lr_start_transaction("UC04_T05_logout");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLogoutRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(18);
			
				web_custom_request("AccountLogoutRequest", 
					"URL={host}/accountservice/ws/AccountLogoutRequest", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/xml", 
					"Referer={host}/", 
					"Snapshot=t18.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{user_id}</loginUser><base64Token>Basic {token}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
					LAST);
			lr_end_transaction("UC04_T05_logout",LR_AUTO);
		lr_end_transaction("Logout", LR_AUTO);
	lr_end_transaction("UC04_Add_to_cart", LR_AUTO);

	return 0;
}