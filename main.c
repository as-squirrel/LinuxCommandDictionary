#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char command[50];
    char description[200];
} CommandEntry;

// General Linux command dictionary
CommandEntry linuxDictionary[] = {
    {"wget", "Download files from the web"},
    {"curl", "Transfer data using various protocols"},
    {"tar", "Archive and extract files"},
    {"grep", "Search for patterns in files"},
    {"sed", "Stream editor for filtering and transforming text"},
    {"awk", "Text processing language"},
    {"ssh", "Secure shell, remote login"},
    {"scp", "Securely copy files between hosts"},
    {"rsync", "Remote file synchronization"},
    {"chmod", "Change file permissions"},
    {"chown", "Change file ownership"},
    {"chgrp", "Change group ownership"},
    {"df", "Display disk space usage"},
    {"du", "Estimate file and directory space usage"},
    {"free", "Display system memory usage"},
    {"ps", "Display information about running processes"},
    {"kill", "Send signals to processes"},
    {"man", "Display manual pages"},
    {"history", "Display command history"},
    {"uname", "Print system information"},
    {"ifconfig", "Configure network interfaces"},
    {"netstat", "Display network connections"},
    {"ping", "Send ICMP Echo Request to a network host"},
    // Add more commands...
};

// nmap command dictionary
CommandEntry nmapDictionary[] = {
    {"nmap", "Network exploration tool and security scanner"},
    {"nmap -sP", "Ping scan - determine which hosts are up"},
    {"nmap -p", "Port scan - scan specified ports"},
    {"nmap -A", "Aggressive scan - enable OS detection, version detection, script scanning, and traceroute"},
    {"nmap -T4", "Timing template - specify the speed of the scan (0-5)"},
    // Add more commands...
};

// System administration commands
CommandEntry systemCommandsDictionary[] = {
    {"apt-get", "Package handling utility for Debian-based systems"},
    {"yum", "Package manager for RPM-based systems"},
    {"systemctl", "Control the systemd system and service manager"},
    {"journalctl", "Query the systemd journal"},
    {"useradd", "Create a new user or update default new user information"},
    {"userdel", "Delete a user account and related files"},
    {"passwd", "Change user password"},
    // Add more commands...
};

// Version Control commands
CommandEntry versionControlDictionary[] = {
    {"git", "Distributed version control system"},
    {"svn", "Apache Subversion version control system"},
    {"hg", "Distributed revision control system"},
    // Add more commands...
};

// Network administration commands
CommandEntry networkCommandsDictionary[] = {
    {"ifconfig", "Configure network interfaces"},
    {"ping", "Send ICMP Echo Request to a network host"},
    {"netstat", "Display network connections"},
    {"nslookup", "Query Internet name servers"},
    {"traceroute", "Print the route packets trace to network host"},
    // Add more commands...
};

void printCommand(CommandEntry command) {
    printf("Command: %s\n", command.command);
    printf("Description: %s\n", command.description);
}

int main() {
    char searchCommand[50];
    char choice;
    int i;
    bool found = false;

    printf("Linux Command Dictionary\n");
    printf("------------------------\n");

    while (true) {
        printf("Choose a dictionary:\n");
        printf("1. General Linux Commands\n");
        printf("2. nmap Commands\n");
        printf("3. System Commands\n");
        printf("4. Version Control Commands\n");
        printf("5. Network Commands\n");
        printf("Enter dictionary choice (1-5) or 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q') {
            printf("Exiting...\n");
            break;
        }

        int dictionaryChoice = choice - '0';

        if (dictionaryChoice < 1 || dictionaryChoice > 5) {
            printf("Invalid choice. Please try again.\n\n");
            continue;
        }

        while (true) {
            printf("Enter a command to search (or 'q' to go back): ");
            scanf("%s", searchCommand);

            if (strcmp(searchCommand, "q") == 0) {
                printf("Going back...\n");
                break;
            }

            found = false;

            switch (dictionaryChoice) {
                case 1: // General Linux command dictionary
                    for (i = 0; i < sizeof(linuxDictionary) / sizeof(CommandEntry); i++) {
                        if (strcmp(searchCommand, linuxDictionary[i].command) == 0) {
                            printCommand(linuxDictionary[i]);
                            found = true;
                            break;
                        }
                    }
                    break;

                case 2: // nmap command dictionary
                    for (i = 0; i < sizeof(nmapDictionary) / sizeof(CommandEntry); i++) {
                        if (strcmp(searchCommand, nmapDictionary[i].command) == 0) {
                            printCommand(nmapDictionary[i]);
                            found = true;
                            break;
                        }
                    }
                    break;

                case 3: // System administration commands
                    for (i = 0; i < sizeof(systemCommandsDictionary) / sizeof(CommandEntry); i++) {
                        if (strcmp(searchCommand, systemCommandsDictionary[i].command) == 0) {
                            printCommand(systemCommandsDictionary[i]);
                            found = true;
                            break;
                        }
                    }
                    break;

                case 4: // Version Control commands
                    for (i = 0; i < sizeof(versionControlDictionary) / sizeof(CommandEntry); i++) {
                        if (strcmp(searchCommand, versionControlDictionary[i].command) == 0) {
                            printCommand(versionControlDictionary[i]);
                            found = true;
                            break;
                        }
                    }
                    break;

                case 5: // Network administration commands
                    for (i = 0; i < sizeof(networkCommandsDictionary) / sizeof(CommandEntry); i++) {
                        if (strcmp(searchCommand, networkCommandsDictionary[i].command) == 0) {
                            printCommand(networkCommandsDictionary[i]);
                            found = true;
                            break;
                        }
                    }
                    break;
            }

            if (!found) {
                printf("Command not found in the dictionary. Please try again.\n\n");
            }
        }
    }

    return 0;
}
