*This project has been created as part of the 42 curriculum by caida-si.*

# NetPractice

## Description

NetPractice is an educational platform designed to teach networking fundamentals through hands-on exercises. The project provides a series of networking challenges that progressively increase in difficulty, helping learners understand IP addressing, routing, and network configuration concepts.

**Goal**: To introduce students to the basics of computer networking by configuring IP addresses, connecting devices through routers, and understanding the role of gateways within networks. Through 10 practical exercises, learners develop competency in TCP/IP addressing, subnet configuration, and network topology design.

## Resources

### Networking Concepts Covered

This project covers essential networking fundamentals:

- **TCP/IP Addressing**: Understanding IP address structure, classes, and allocation
- **Subnet Masks**: Calculating subnets and subnet ranges
- **CIDR Notation**: Classless Inter-Domain Routing for efficient address management
- **Default Gateways**: Routing traffic between networks and network segments
- **Routers and Switches**: Network devices and their roles in data transmission
- **Routing Tables**: Configuring static routes for network communication
- **OSI Layers**: Understanding the role of different layers in network communication
- **Network Design**: Topology planning and device interconnection
- **IP Routing**: Forward decision-making and path selection

### Reference Documentation

- **RFC 791 - Internet Protocol**: [https://tools.ietf.org/html/rfc791](https://tools.ietf.org/html/rfc791)
- **RFC 1918 - Private Internet Addresses**: [https://tools.ietf.org/html/rfc1918](https://tools.ietf.org/html/rfc1918)
- **Subnet Calculator**: Available via the training interface
- **TCP/IP Protocol Suite**: Comprehensive reference on networking protocols
- **OSI Model Reference**: Understanding the 7-layer networking model

### Technical References

- **IPv4 Addressing Guide**: Study TCP/IP addressing to strengthen understanding of network configuration
- **Network Configuration Best Practices**: Learn how to design and validate network topologies
- **Packet Flow Analysis**: Understanding how data moves through networks using routing tables

### AI Usage in this Project

AI tools were used to:
- **Documentation**: Generating initial README structure and layout
- **Task**: Creating formatted documentation following project requirements
- **Implementation**: No AI was used for the actual network configuration exercises or solution files. All networking problem-solving was completed manually by the student.
- **Content Review**: AI was used to ensure clarity and completeness of documentation against subject requirements

All actual networking concepts, configurations, and solutions were derived from direct learning and manual problem-solving.

## Instructions

### Prerequisites

- Python 3
- A modern web browser
- Unix-like system (Linux, macOS)

### Running the Training Interface

1. Navigate to the project directory:
```bash
cd netpractice/net_practice.1.9/net_practice
```

2. Start the web server using the provided script:
```bash
./run.sh
```

The script will:
- Find an available port (starting from 49242)
- Automatically open your default web browser
- Display the URL if automatic opening fails

**Manual alternative**: If `run.sh` does not work, run:
```bash
python3 -m http.server 49242
```
Then navigate to `http://localhost:49242` in your web browser.

3. **Configure your login**:
   - Enter your intranet login in the "Training" tab to use your personal configuration
   - Alternatively, use the "Evaluation" tab to generate a random configuration

4. **Complete the levels**:
   - Solve 10 levels of increasing difficulty
   - For each level, modify unshaded fields until the network configuration is correct
   - Use the **[Check again]** button to verify your configuration
   - Logs at the bottom of the page will help you understand any errors

### Exporting Configurations

After successfully completing each level:

1. Click the **[Get my config]** button to download your configuration file
2. Place each of the 10 configuration files at the root of your Git repository
3. The files should be named according to their level (e.g., `level1.json`, `level2.json`, etc.)

**Important**: You must export and submit configuration files for all 10 levels.

### Evaluation

- In the "Evaluation" tab, you can practice the timed evaluation mode
- You will have **15 minutes** to randomly selected 3 levels from difficulty 6-10
- During official evaluation, you are only allowed to use a simple calculator (e.g., `bc`)
- No external tools are permitted during evaluation 
