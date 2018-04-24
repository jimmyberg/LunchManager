# LunchManager

A simple terminal program you can use when sharing lunch with your coworkers. 

* This program keeps track of credit/debit for each user.
* For every lunch the one who buys lunch gets credit according to: cost*(N-1)/N credit and others will pay cost/N credit.
* It is currently completly thrust base so no password support (yet).

# How to use
1. Edit the config.h file. It is recommended to use your home folder as save location(/home/<username>)
2. Compile by running `make` or compile it yourself however you like.
3. Run the binary, default called prog. `./prog`
4. When running type `help` for details on how to use it. It is pretty straight forward.

Now you can put the binary (prog) wherever you like. Run it when having lunch or keep it open on a dedicated Raspberry PI or something.
