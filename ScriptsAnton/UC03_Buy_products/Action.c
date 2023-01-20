Action()
{
	lr_start_transaction("UC03_Buy_products");
		web_set_sockets_option("SSL_VERSION", "AUTO");
	
		web_set_user("Glovindan", 
			lr_unmask("63950723db969836f41077155f0abec7"), 
			"advantageonlineshopping.com:443");
	
		web_add_cookie("_gid=GA1.2.865475626.1670695575; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("userCart=%7B%22userId%22%3A-1%2C%22productsInCart%22%3A%5B%5D%7D; DOMAIN=advantageonlineshopping.com");
	
		web_add_cookie("_ga=GA1.2.1596872114.1670427346; DOMAIN=advantageonlineshopping.com");
	
		web_url("advantageonlineshopping.com", 
			"URL={host}", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t66.inf", 
			"Mode=HTML", 
			EXTRARES, 
			"Url=/css/fonts/roboto_regular_macroman/Roboto-Regular-webfont.eot?", ENDITEM, 
			"Url=/css/fonts/roboto_light_macroman/Roboto-Light-webfont.eot?", ENDITEM, 
			"Url=/main.min.js", ENDITEM, 
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
			"Url=/catalog/fetchImage?image_id=tablets", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=mice", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=laptops", ENDITEM, 
			"Url=/css/images/twitter.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=headphones", ENDITEM, 
			"Url=/css/images/linkedin.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=speakers", ENDITEM, 
			"Url=/css/images/Popular-item1.jpg", ENDITEM, 
			"Url=/css/images/arrow_right.png", ENDITEM, 
			"Url=/css/images/Popular-item2.jpg", ENDITEM, 
			"Url=/css/images/Filter.png", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4200", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4500", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4300", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4600", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4100", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4700", ENDITEM, 
			"Url=/catalog/fetchImage?image_id=4400", ENDITEM, 
			"Url=/css/images/category_banner_4.png", ENDITEM, 
			"Url=/css/images/User.jpg", ENDITEM, 
			"Url=/css/images/Shipex.png", ENDITEM, 
			"Url=/css/images/Bell.png", ENDITEM, 
			"Url=/css/images/Check.png", ENDITEM, 
			LAST);
	
		web_url("ALL", 
			"URL={host}/catalog/api/v1/DemoAppConfig/parameters/by_tool/ALL", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t67.inf", 
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
			"Snapshot=t68.inf", 
			"Mode=HTML", 
			"EncType=text/xml; charset=UTF-8", 
			"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountConfigurationRequest xmlns=\"com.advantage.online.store.accountservice\"></GetAccountConfigurationRequest></soap:Body></soap:Envelope>", 
			LAST);
		
	//		*************************
	//		Выбор случайной категории
	//		*************************
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
			"Snapshot=t69.inf", 
			"Mode=HTML", 
			LAST);
		
		lr_save_string(lr_paramarr_random("category_all"), "category_rand");
		
		web_add_cookie("_gat=1; DOMAIN=advantageonlineshopping.com");
	
		web_url("search", 
			"URL={host}/catalog/api/v1/deals/search?dealOfTheDay=true", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}/", 
			"Snapshot=t70.inf", 
			"Mode=HTML", 
			LAST);
	
		web_url("popularProducts.json", 
			"URL={host}/app/tempFiles/popularProducts.json", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={host}", 
			"Snapshot=t71.inf", 
			"Mode=HTML", 
			LAST);
	
		web_url("home-page.html", 
			"URL={host}/app/views/home-page.html", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer={host}/", 
			"Snapshot=t72.inf", 
			"Mode=HTML", 
			LAST);
		
		lr_start_transaction("Login");
			lr_start_transaction("UC03_TR01_Login");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLoginRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(5);
		
		//		*************************
		//		Авторизация, сохранение токена, sessionId и id пользователя
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
					"Snapshot=t73.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLoginRequest xmlns=\"com.advantage.online.store.accountservice\"><email></email><loginPassword>{password}</loginPassword><loginUser>{user}</loginUser></AccountLoginRequest></soap:Body></soap:Envelope>", 
					LAST);
			
				web_set_sockets_option("INITIAL_AUTH", "BASIC");
				
				web_add_auto_header("Authorization:", "Basic {token}");
				
				web_reg_save_param_json(
					"ParamName=sessionId",
					"QueryString=$..sessionId",
					"SelectAll=No",
					SEARCH_FILTERS,
					LAST);
			
				web_url("carts/userId", 
					"URL={host}/order/api/v1/carts/{userId}", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t74.inf", 
					"Mode=HTML", 
					LAST);
			lr_end_transaction("UC03_TR01_Login",LR_AUTO);
		lr_end_transaction("Login", LR_AUTO);
	
		
		lr_think_time(24);
	
		lr_start_transaction("UC03_TR02_Category_select");
	//		*************************
	//		Выбор случайного продукта
	//		*************************
			web_reg_save_param_json(
				"ParamName=category_products_all",
				"QueryString=$..products.[?(@.productStatus == \"Active\")].productId",
				"SelectAll=Yes",
				SEARCH_FILTERS,
				LAST);
			
			web_url("products", 
				"URL={host}/catalog/api/v1/categories/{category_rand}/products", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={host}/", 
				"Snapshot=t75.inf", 
				"Mode=HTML", 
				LAST);
		
			lr_save_string(lr_paramarr_random("category_products_all"), "category_products_rand");	
			
			web_url("attributes", 
				"URL={host}/catalog/api/v1/categories/attributes", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={host}/", 
				"Snapshot=t76.inf", 
				"Mode=HTML", 
				LAST);
		
			web_url("category-page.html", 
				"URL={host}/app/views/category-page.html", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer={host}/", 
				"Snapshot=t77.inf", 
				"Mode=HTML", 
				LAST);
		lr_end_transaction("UC03_TR02_Category_select",LR_AUTO);
	
		lr_think_time(22);
		
		lr_start_transaction("Product_select");
			lr_start_transaction("UC03_TR03_Product_select");
		//		*************************
		//		Выбор случайного цвета
		//		*************************
				web_reg_save_param_json(
					"ParamName=colors_all",
					"QueryString=$..code",
					"SelectAll=Yes",
					SEARCH_FILTERS,
					LAST);
			
				web_url("products/category_products_rand", 
					"URL={host}/catalog/api/v1/products/{category_products_rand}", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t78.inf", 
					"Mode=HTML", 
					LAST);
			
				lr_save_string(lr_paramarr_random("colors_all"), "colors_rand");	
				
				web_url("all_data", 
					"URL={host}/catalog/api/v1/categories/all_data", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t80.inf", 
					"Mode=HTML", 
					LAST);
			
				web_url("product-page.html", 
					"URL={host}/app/views/product-page.html", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/html", 
					"Referer={host}/", 
					"Snapshot=t81.inf", 
					"Mode=HTML", 
					LAST);
		
			lr_end_transaction("UC03_TR03_Product_select",LR_AUTO);
		lr_end_transaction("Product_select",LR_AUTO);
	
		lr_think_time(44);
		
		lr_start_transaction("Cart_add");
			lr_start_transaction("UC03_TR04_Cart_add");
				web_submit_data("color/colors_rand", 
					"Action={host}/order/api/v1/carts/{userId}/product/{category_products_rand}/color/{colors_rand}?quantity=1", 
					"Method=POST", 
					"TargetFrame=", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t82.inf", 
					"Mode=HTML", 
					ITEMDATA, 
					"Name=sessionId", "Value={sessionId}", ENDITEM, 
					LAST);
			lr_end_transaction("UC03_TR04_Cart_add",LR_AUTO);
		lr_end_transaction("Cart_add",LR_AUTO);
	
		lr_think_time(37);
		
		lr_start_transaction("UC03_TR05_Checkout");
			web_url("shoppingCart.html", 
						"URL={host}/app/views/shoppingCart.html", 
						"TargetFrame=", 
						"Resource=0", 
						"RecContentType=text/html", 
						"Referer={host}/", 
						"Snapshot=t84.inf", 
						"Mode=HTML", 
						LAST);
				
			web_add_header("SOAPAction", 
				"com.advantage.online.store.accountserviceGetAccountByIdRequest");
		
			web_add_auto_header("X-Requested-With", 
				"XMLHttpRequest");
		
			web_custom_request("GetAccountByIdRequest", 
				"URL={host}/accountservice/ws/GetAccountByIdRequest", 
				"Method=POST", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/xml", 
				"Referer={host}/", 
				"Snapshot=t85.inf", 
				"Mode=HTML", 
				"EncType=text/xml; charset=UTF-8", 
				"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {token}</base64Token></GetAccountByIdRequest></soap:Body></soap:Envelope>", 
				LAST);
		
			web_add_header("SOAPAction", 
				"com.advantage.online.store.accountserviceGetAccountByIdNewRequest");
		
			web_custom_request("GetAccountByIdNewRequest", 
				"URL={host}/accountservice/ws/GetAccountByIdNewRequest", 
				"Method=POST", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/xml", 
				"Referer={host}/", 
				"Snapshot=t86.inf", 
				"Mode=HTML", 
				"EncType=text/xml; charset=UTF-8", 
				"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountByIdNewRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic {token}</base64Token></GetAccountByIdNewRequest></soap:Body></soap:Envelope>", 
				LAST);
		
			web_revert_auto_header("X-Requested-With");
			
			web_custom_request("shippingcost", 
				"URL={host}/order/api/v1/shippingcost/", 
				"Method=POST", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer={host}/", 
				"Snapshot=t88.inf", 
				"Mode=HTML", 
				"EncType=application/json;charset=utf-8", 
				"Body={\"seaddress\":{\"addressLine1\":\"asdasda\",\"addressLine2\":\"\",\"city\":\"asdasdasd\",\"country\":\"um\",\"postalCode\":\"asdasddasd\",\"state\":\"asasdasd\"},\"secustomerName\":\"asdasd asdasdas\",\"secustomerPhone\":\"\",\"senumberOfProducts\":1,\"setransactionType\":\"SHIPPING_COST\",\"sessionId\":\"{sessionId}\"}", 
				LAST);
		
			web_add_header("SOAPAction", 
				"com.advantage.online.store.accountserviceGetAccountPaymentPreferencesRequest");
		
			web_add_header("X-Requested-With", 
				"XMLHttpRequest");
		
			web_custom_request("GetAccountPaymentPreferencesRequest", 
				"URL={host}/accountservice/ws/GetAccountPaymentPreferencesRequest", 
				"Method=POST", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/xml", 
				"Referer={host}/", 
				"Snapshot=t89.inf", 
				"Mode=HTML", 
				"EncType=text/xml; charset=UTF-8", 
				"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetAccountPaymentPreferencesRequest xmlns=\"com.advantage.online.store.accountservice\"><accountId>{userId}</accountId><base64Token>Basic R2xvdmluZGFuOkdsb3ZpbmRhbjEyMw==</base64Token></GetAccountPaymentPreferencesRequest></soap:Body></soap:Envelope>", 
				LAST);
		
			web_url("orderPayment-page.html", 
				"URL={host}/app/order/views/orderPayment-page.html", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer={host}/", 
				"Snapshot=t90.inf", 
				"Mode=HTML", 
				LAST);
		
			web_add_header("SOAPAction", 
				"com.advantage.online.store.accountserviceGetCountriesRequest");
		
			web_add_auto_header("X-Requested-With", 
				"XMLHttpRequest");
		
			web_custom_request("GetCountriesRequest", 
				"URL={host}/accountservice/ws/GetCountriesRequest", 
				"Method=POST", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/xml", 
				"Referer={host}/", 
				"Snapshot=t91.inf", 
				"Mode=HTML", 
				"EncType=text/xml; charset=UTF-8", 
				"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><GetCountriesRequest xmlns=\"com.advantage.online.store.accountservice\"></GetCountriesRequest></soap:Body></soap:Envelope>", 
				LAST);
		
			web_add_header("SOAPAction", 
				"com.advantage.online.store.accountserviceUpdateSafePayMethodRequest");
		lr_end_transaction("UC03_TR05_Checkout",LR_AUTO);
		
		lr_think_time(5);
		
		lr_start_transaction("Cart_buy");
			lr_start_transaction("UC03_TR06_Cart_buy");
				web_custom_request("UpdateSafePayMethodRequest", 
					"URL={host}/accountservice/ws/UpdateSafePayMethodRequest", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/xml", 
					"Referer={host}/", 
					"Snapshot=t92.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><UpdateSafePayMethodRequest xmlns=\"com.advantage.online.store.accountservice\"><userId>{userId}</userId><safePayUsername>userNAme</safePayUsername><safePayPassword>d02b3fe2bf2e</safePayPassword><referenceId>1234567890</referenceId><base64Token>Basic "
					"{token}</base64Token></UpdateSafePayMethodRequest></soap:Body></soap:Envelope>", 
					LAST);
			
				web_revert_auto_header("X-Requested-With");
			
				web_custom_request("384472445_4", 
					"URL={host}/order/api/v1/orders/users/{userId}", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer={host}/", 
					"Snapshot=t93.inf", 
					"Mode=HTML", 
					"EncType=application/json", 
					"Body={\"orderPaymentInformation\":{\"Transaction_AccountNumber\":\"843200971\",\"Transaction_Currency\":\"USD\",\"Transaction_CustomerPhone\":\"\",\"Transaction_MasterCredit_CVVNumber\":\"\",\"Transaction_MasterCredit_CardNumber\":\"4886\",\"Transaction_MasterCredit_CustomerName\":\"\",\"Transaction_MasterCredit_ExpirationDate\":\"122027\",\"Transaction_PaymentMethod\":\"SafePay\",\"Transaction_ReferenceNumber\":0,\"Transaction_SafePay_Password\":\"d02b3fe2bf2e27940de402c3f2cce301c3c8637f\",\""
					"Transaction_SafePay_UserName\":\"userNAme\",\"Transaction_TransactionDate\":\"10122022\",\"Transaction_Type\":\"PAYMENT\"},\"orderShippingInformation\":{\"Shipping_Address_Address\":\"asdasda\",\"Shipping_Address_City\":\"asdasdasd\",\"Shipping_Address_CountryCode\":40,\"Shipping_Address_CustomerName\":\"asdasd asdasdas\",\"Shipping_Address_CustomerPhone\":\"\",\"Shipping_Address_PostalCode\":\"asdasddasd\",\"Shipping_Address_State\":\"asasdasd\",\"Shipping_Cost\":269.99,\""
					"Shipping_NumberOfProducts\":1,\"Shipping_TrackingNumber\":0},\"purchasedProducts\":[{\"hexColor\":\"{colors_rand}\",\"productId\":{category_products_rand},\"quantity\":1,\"hasWarranty\":false}]}", 
					LAST);
			lr_end_transaction("UC03_TR06_Cart_buy",LR_AUTO);
		lr_end_transaction("Cart_buy",LR_AUTO);
		
		lr_start_transaction("Logout");
			lr_start_transaction("UC03_TR07_Exit");
				web_add_header("SOAPAction", 
					"com.advantage.online.store.accountserviceAccountLogoutRequest");
			
				web_add_header("X-Requested-With", 
					"XMLHttpRequest");
			
				lr_think_time(19);
			
				web_custom_request("AccountLogoutRequest", 
					"URL={host}/accountservice/ws/AccountLogoutRequest", 
					"Method=POST", 
					"TargetFrame=", 
					"Resource=0", 
					"RecContentType=text/xml", 
					"Referer={host}/", 
					"Snapshot=t95.inf", 
					"Mode=HTML", 
					"EncType=text/xml; charset=UTF-8", 
					"Body=<?xml version=\"1.0\" encoding=\"UTF-8\"?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\"><soap:Body><AccountLogoutRequest xmlns=\"com.advantage.online.store.accountservice\"><loginUser>{userId}</loginUser><base64Token>{token}</base64Token></AccountLogoutRequest></soap:Body></soap:Envelope>", 
					LAST);
			lr_end_transaction("UC03_TR07_Exit",LR_AUTO);
		lr_end_transaction("Logout",LR_AUTO);
	lr_end_transaction("UC03_Buy_products",LR_AUTO);
	return 0;
}