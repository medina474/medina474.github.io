
Podman is a daemonless container engine for developing, managing, and running OCI Containers on your Linux System. In this article, we will introduce podman and how to use it with a small application build using nodejs. The app will be very simple and clean.
Install Podman

Podman command is the same as docker just type in your terminal `alias docker=podman` if you have docker already installed

Podman is installed by default in Fedora Linux. 




This article, will introduce Podman Pods and demonstrate how to use them with a simple application built using Node.js. The app will be lightweight and easy to set up, showcasing the power of running multiple containers in a pod.
What is a Podman Pod?

Podman pod is a group of containers that share the same network, storage, and process namespace. Kubernetes pods inspires it. Pods allow you to run multiple containers that need to work closely together, like a web server and a caching service, in a single isolated unit.

Pods in Podman provide a native way to group containers without needing a full Kubernetes setup. This makes them ideal for development and small-scale applications.

Install Podman

Podman is included by default in Fedora Linux, but if it’s not installed for any reason, you can add it with the following command:

$ sudo dnf install podman -y

To verify your installation, you can run a quick hello-world container:

After installation, run the hello world image to ensure everything is working:

```shell
podman pull hello-world 
podman run hello-world
```

If everything is working well you will see the following output in your terminal:

Hello from Docker! 
This message shows that your installation appears to be working correctly.
 To generate this message, Docker took the following steps:
  1.The Docker client contacted the Docker daemon.
  2.The Docker daemon pulled the "hello-world" image from the Docker Hub. (amd64)
  3.The Docker daemon created a new container from that image which runs the executable that produces the output you are currently reading.
  4.The Docker daemon streamed that output to the Docker client, which sent it to your terminal. 
 To try something more ambitious, you can run an Ubuntu container with:
  $ docker run -it ubuntu bash
 Share images, automate workflows, and more with a free Docker ID:
  https://hub.docker.com/
 For more examples and ideas, visit:
  https://docs.docker.com/get-started/

### Simple Nodejs App

First, we will create a folder webapp , type the following command in your terminal

mkdir webapp && cd webapp

Now create the file package.json This file includes all the dependencies that the project needs to work well. Copy the following code inside the file package.json .

```json
{
       "dependencies": {
               "express": "*"
       },
       "scripts": {
               "start": "node index.js"
       }
}
```

Create the file index.js and add the following code there:

```js
const express = require('express')

const app = express();

app.get('/', (req, res)=> {
       res.send("Hello World!")
});
app.listen(8080, () => {
       console.log("Listing on port 8080");
});
```

Create Dockerfile

First of all, create a file called Dockerfile and make sure the first character is a capital, NOT lower case, then add the following code there:

```dockerfile
FROM node:alpine
WORKDIR usr/app
COPY ./ ./
RUN npm install
CMD ["npm", "start"]
```

Be sure you are inside the folder webapp then show the image and then type the following command:

```shell
podman build .
```

Make sure to add the dot. The image is created on your machine and you can show it using the following command:

```shell
podman images
```

The last step is to run the image inside a container by typing the following command:

```shell
podman run -p 8080:8080 <image-name>
```

Now open your browser in localhost:8080 and you will see that your app works.
Stopping and Remove Container

To exit from the container use CTRL-C. You can remove the container by using the container id. Get the id and stop the container using these commands:

```shell
podman ps -a
podman stop <container_id>
```

You can delete the images from your machine by using the following command:

```shell
podman rmi <image_id>
```

Read more about podman and how it works on the official website


$ podman pull hello-world
$ podman run hello-world

If everything is set up correctly, you’ll see output similar to:

Hello from Docker!

This shows that Podman is up and running, and ready for the next steps.
Starting with a Simple Node.js App in a Pod

To start this example, create a simple web application using Node.js. First, create a directory for the app:

$ mkdir webapp && cd webapp

Inside the webapp directory, create a package.json file that lists the dependencies your project needs:

{
"dependencies": {
"express": "*"
},
"scripts": {
"start": "node index.js"
}
}

Next, create an index.js file that will serve a basic “Hello World” response:

const express = require('express');
const app = express();

app.get('/', (req, res) => {
    res.send("Hello World!");
});

app.listen(8080, () => {
    console.log("Listening on port 8080");
});

Create a Dockerfile for the App

Now, create a Dockerfile in the same directory to build the container image for your app:

FROM node:alpine
WORKDIR /usr/app
COPY ./ ./
RUN npm install
CMD ["npm", "start"]

This Dockerfile will pull a lightweight Node.js image, install the necessary dependencies, and start the app.
Build the Image Using Podman

To build the container image for your app, use the following command:

$ podman build -t webapp .

The -t flag names the image webapp, and the . specifies the current directory as the build context.

Create and Run a Pod with Podman

Now that the image is ready, it’s time to create a pod and run the container inside it. First, create a pod:

$ podman pod create --name mypod -p 8080:8080

This creates a pod named mypod and maps port 8080 on the host to port 8080 inside the pod.
Next, run the Node.js container inside the pod:

$ podman run -d --pod mypod --name webapp-container webapp

The –pod flag specifies that the container should run inside mypod.
Add Another Container to the Pod

One of the key features of pods is the ability to run multiple containers that share resources. For example, let’s add a Redis container to the same pod:

$ podman run -d --pod mypod --name redis-container redis

Now, both the webapp and redis containers are running inside the same pod, sharing the network namespace. This means the webapp can communicate with redis over localhost.
Check Pod and Container Status

The status of the pod and its containers can be verified using:

$ podman pod ps
$ podman ps --pod

These commands will show you the pod’s status and its running containers.
Stopping and Removing the Pod

To stop the pod and all its containers:

$ podman pod stop mypod

To remove the pod and all its containers:

$ podman pod rm mypod

Conclusion

Podman pods offer an easy way to group and manage containers, making it simple to run applications that require multiple containers that must work together. With Podman’s built-in pod support, it is possible to use Kubernetes-like functionality without the complexity.

https://fedoramagazine.org/simplifying-container-management-with-podman-pods-on-fedora-linux/
