#include "generate.h"



void generateFolders(std::string projName){
	std::string FOLDERS[9] = {
								"/app",
								"/app/routes",
								"/app/db",
								"/app/templates",
								"/app/static",
								"/app/static/images",
								"/app/static/js",
								"/app/static/styles"
							};
	std::filesystem::create_directory(projName);

	for(std::string folder : FOLDERS){
		std::filesystem::create_directory(projName + folder);
	}
}

void generateFiles(std::string projName){
	std::ofstream outFile;

	std::map<std::string, std::string> FILES {
		{
			"/app.py", "from app import app as application\nif __name__ == \"__main__\":\n\tapplication.run(host='0.0.0.0',debug=True)"
		},
		{
			"/requirements.txt", "Flask\nFlask-Cors\ngunicorn"
		},
		{
			"/app/__init__.py", "from flask import Flask\nfrom flask_cors import CORS\napp=Flask(__name__)\nCORS(app)\nfrom app.routes import mainRoutes"
		},
		{
			"/app/routes/mainRoutes.py","from app import app\nfrom app.db import mainDB\nfrom flask import request\n\n@app.route('/',methods=['GET'])\ndef index():\n\tif(request.method == 'GET'):\n\t\treturn(mainDB.getDBData())"
		},
		{
			"/app/routes/__init__.py",""	
		},
		{
			"/app/db/mainDB.py","def getDBData():\n\treturn('HELLO THERE. HAVE FUN WITH YOU NEW PROJECT')"
		},
		{
			"/app/db/__init__.py", ""
		},
		{
			"/Procfile","web: gunicorn -w 2 -b 0.0.0.0:5000 app:app"
		},
		{
			"/Dockerfile","FROM python:alpine\n\nWORKDIR /app\n\nCOPY requirements.txt .\n\nRUN pip install -r requirements.txt\n\nCOPY . .\n\nCMD [\"gunicorn\"  , \"-w\" , \"2\", \"-b\", \"0.0.0.0:5000\", \"app:app\"]"
		},
		{
			"/.gitignore","__pycache__/\n.vscode/\n.idea/"
		}
	};

	for (auto const& [key, val] : FILES){
		outFile.open(projName + key,std::ios::trunc);
		outFile << val;
		outFile.close();
	}
}