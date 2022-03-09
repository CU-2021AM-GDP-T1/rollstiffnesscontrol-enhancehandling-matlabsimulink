# rollstiffnesscontrol-enhancehandling-matlabsimulink
Repository for Cranfield University, 2021 Automotive Mechatronics, Group Design Project Team 1, Topic : Roll Stiffness Control for Enhanced Handling of Performance Vehicles 

## Starting Information
Resources for getting started with Version Control with MATLAB and Simulink
Get the remote GitHub repository cloned to your local folder
Watch this video on how to do it, starting at 1m6s: https://youtu.be/O7A27uMduo0?t=66After 

After cloning the project, you will see that the file are organized via a Project, within MATLAB, open the  PRJ file and make use of the functionalities shown in the below link.

MATLAB and Simulink Projects: https://uk.mathworks.com/videos/matlab-and-simulink-projects-in-r2019a-1557464906514.html

## Standard/Preferred Practices
1. When testing or implementing new function, DO NOT commit directly to the main branch, DO create a new branch and start a new pull request, and later push the changes. This is mandatory now for the protected "main" and "develop" brances, which will require a manual review before the pull request is approved to merge the changes to the original branch.
2. Use lowercase and hyphen for naming on github, use uppercase only when it is a short hand for something. Try naming things following semantics, for example the name of this project follows the format projectname-projectpurpose-language, i.e. rollstiffnesscontrol-enhancehandling-matlabsimulink.
3. For naming branches, follow this: yourgitname-originalbranchname-purposeofthisnewbranch, for example, this point is writtn under the branch CCTJB2-main-amendrootfoldercontent, and I try to only add or change things like the gitignore gitattributes and this README.md file in the root folder of the project, with respect to the main branch.

## Common Troubleshooting
1. "Updates were rejected because the remote contains work that you do hint: not have locally", pull from remote repo first before pushing for the first time.
2. Matlab cannot add files under sub-folders in a batch, to do that, use the git command line by installing git to your PC. CD to the local repo folder and use the command "git add .", the dot means all files, specify files if needed.
To revert addition to "staged" changes, use "git reset .", specify files if needed.
