#ifndef CONFIG_H
#define CONFIG_H

// ---------------------------------[ ~ CONFIG ~ ]------------------------
/*
                Colors table: | Tabela kolorów: | Farbtabelle: | [place for other languages]
                RED           | Czerwony        | Rot              |
                BLACK         | Czarny          | Schwarz      |
                WHITE         | Biały           | Weiß         |
                RAYWHITE      | Ciemny biały    | Dunkelweiß   |
                BLUE          | Niebieski       | Blau         |
                GREEN         | Zielony         | Grün         |
*/
// ---------------------------------[ Window cnf. ]-----------------------

        static const int window_width = 500;
        static const int window_height = 500;
        static const int window_max_fps = 30;
	static const Color text_color = WHITE;

	static const Color line_color = RED;	
	static const bool line_visible = 1;

// ---------------------------------[ Paddles cnf ]-----------------------

        static const float paddle_width = 20;
        static const float paddle_height = 80;
        static const Color paddle_color = RED;
	static const int paddles_speed = 200;
	int p1s = 0;
	int p2s = 0;

// ---------------------------------[ Ball conf. ]------------------------

        static const float ball_radius = 20;
        static const Color ball_color = RED;

// ---------------------------------[ Game conf. ]------------------------
       	
	static const int scr = 1;
       	static const bool sounds = 1;

// ---------------------------------[ END CONFIG ]------------------------

#endif
