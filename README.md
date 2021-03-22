# Flask Template Generator

This is a small utility to generate a flask template for APIs/Webpage hosting which I made after I got tired of recreating the flask app everytime. Generate a single executable which can be added to path and used to generate the template anywhere.

##### note :
This app requires c++17 features to use.

### Usage
```bash
$ flaskcreate :project Name:
```

The utility generate a flask app with the following structure
```
Project Name
    ├── Dockerfile
    ├── Procfile
    ├── app
    │   ├── __init__.py
    │   ├── db
    │   │   ├── __init__.py
    │   │   └── mainDB.py
    │   ├── routes
    │   │   ├── __init__.py
    │   │   └── mainRoutes.py
    │   ├── static
    │   │   ├── images
    │   │   ├── js
    │   │   └── styles
    │   └── templates
    ├── app.py
    └── requirements.txt`
```