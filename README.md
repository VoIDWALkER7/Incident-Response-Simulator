INTRODUCTION:

Cyber Security skills have become integral in today's technologically affluent world. This field involves much more than an adept understanding of technicalities. It necessitates a distinct way of thinking, unrelenting vigilance, originality, and constant adaptation to the ever-evolving threats of the digital landscape. Recognizing this reality, we've spared no effort in designing a comprehensive cybersecurity training platform that simulates actual hacking episodes to help you cultivate this unique mindset and sharpen your skills.
Our transformative Cyber Security training platform breaks the mold of traditional
learning paradigms. It replaces the static, output-oriented learning strategies with an engaging, dynamic experience by capitalizing on the premise of 'learning by doing.' It's an immersive environment where you can go beyond reading and understanding theoretical concepts - you can put your knowledge into practice and learn from first-hand experience.
Moreover, our platform is designed to cater to differing skill levels by allowing customization of the difficulty level of each scenario - from 'Easy' to 'Medium' and 'Hard.' On initiating a scenario, a virtual shell is launched in tandem with an automated script that sets up a genuine situation reflective of the selected attack
type. You will then be tasked with identifying and neutralizing the posed cyber threat using customized hints and feedback that align with your chosen difficulty level. The adaptability and customization options provided by our platform differentiate it from current learning platforms, permitting you to navigate the technical complexities and gain an understanding of a hacker's mindset and approach.
The hands-on approach and collaborative ethos of our platform make the learning process engaging and interactive, making it more than just a program - it's a revolutionized way of acquiring and honing cybersecurity skills. It's a conducive, stimulating, and immersive environment to understand and counter cyber threats effectively.

DESIGN

  2.1 Backend Architecture:
  
   Sandboxing is a security mechanism in cybersecurity testing. Involves creating isolated environments known as "sandbox". 
  
  1. Implementation using Azure Cloud:
        
      - Sandboxing is implemented using Azure Cloud.
        
      - Entire has been website hosted on Azure Cloud.
        
  2. Sandbox Components:
      - Instances running Docker containers used for sandboxing.
       
      - Docker facilitates containerization for security and isolation.
        
  3. Role of Shellinabox:Instances run
       
      - Shellinabox within Docker containers.
       
      - Shellinabox optimizes the sandbox environment.
  
  4. Containerization and Optimization Tools:
      - Docker used for containerization.
      
      - Shellinabox utilized for virtual shell as well as dualling the sandboxing layer.
  
  5. YAML Files for Configuration:
       
      - YAML files streamline creating sandbox environments.
       
      - Enables configuring distinct sandboxes for various attack scenarios.
  
  6. Controlled Environments:
       
      - Approach ensures potential threats are tested in controlled environments.
       
      - Safeguard the integrity of the overall system.

  7. Integration with Azure Cloud:
       
      - Azure Cloud hosts the entire website and sandboxing infrastructure.
       
      - Provides scalability and robust hosting.

  8. Security Measures:
       
      - Docker and Shellinabox enhance efficiency and isolation for security.
       
      - Potential threats understood within controlled environments.
  
2.2 Frotnend Architecture:
    
  1. HTML, CSS, JavaScript: Developed a dynamic and responsive user interface for a web application using HTML for structure, CSS for styling, and JavaScript for client-side interactivity.
  
  2. Login Page: Created a secure and user-friendly login page.Implemented AJAX with JavaScript to communicate asynchronously with the Python CGI backend, ensuring a seamless user experience.
  
  3. The Pages: We have developed three distinct sets of pages catering to different functionalities:
      
      - Login Page

         ![image](https://github.com/VoIDWALkER7/Incident-Response-Simulator/assets/84080270/4df1150f-bc29-4fe8-b45e-371df0920445)
      
      - Home Page : Designed a central hub featuring buttons for various attack scenarios.

         ![image](https://github.com/VoIDWALkER7/Incident-Response-Simulator/assets/84080270/ba7f7326-4374-4ce4-b0f0-c844408e6605)
      
      - Attack Pages : Integrated iframes to embed Shellinabox, offering a terminal-like interface directly on the webpage.

        ![image](https://github.com/VoIDWALkER7/Incident-Response-Simulator/assets/84080270/e05418b1-5b97-4ba5-9ebe-f55191d8e930)

HOW IT WORKS
   
  3.1 How to access the application:
     
  - Clone the github repository using the <git clone> command, then unzip the zip file. [advisable that the git cloning has been done inside a cloud instance. Just makes it easier for you to host in online. Otherwise it works just fine on host machine as well.
  
  - First step is to install apache-httpd to host the website easily, otherwise the login backend will be need to be renewed. Or you can use any server that is to your liking. 
  
  - Replace the IPs in all the places with your ip or your instance's public ip.
  
  - Now, using the terminal, cd into the shellinabox folder, and use the command <docker-compose up> ( you will need to install the command first, in ubuntu it's <apt-get install docker-compose>, in arch it's <pacman -S docker-compose>). Make sure you check the port configuration for each container you launch. and ensure that you are creating a seperate folder for each container.
  
  - Now, open shellinabox in your browser, and create your scripts, or simply copy and paste our scripts.
  
   3.2 Application Flow and Future Flow that will be done in form of a flowchart:
     ![image](https://github.com/VoIDWALkER7/Incident-Response-Simulator/assets/84080270/1984c39c-0ff0-49ec-a687-7c4cd2af8746)

       
