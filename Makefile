NAME = fdf
LIB = ./Libft/libft.a
PRI = ./printf/libftprintf.a

SRCS = main.c calculate.c draw.c error.c init.c iso.c list.c offset.c utils.c free.c

# GNLのソースファイル（gnlフォルダにget_next_line.c, get_next_line_utils.cがあると仮定）
GNL_SRCS = get_next_line.c get_next_line_utils.c
# SRCSにGNLを追加
SRCS += $(GNL_SRCS)


OBJ_DIR = ./objs
OBJS = $(SRCS:.c=.o)

# 修正点 1: MiniLibXのディレクトリとライブラリファイルを定義
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

# 修正点 2: OPTIONをLinux環境用に変更
# -L: libmlx.aの場所を指定
# -lmlx -lXext -lX11: X Window System関連のライブラリとMiniLibXライブラリをリンク
# -lm: 数学ライブラリ (fdfで三角関数などを使う場合に必須)
OPTION = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# 修正点 3: INCLUDEにfdf.hとMiniLibXのヘッダーパスを追加
# -I<path>: コンパイラにヘッダーファイルを探す場所を教える
INCLUDE_PATHS = -I. -I../$(MLX_DIR)

MAIN_INC = -I. -I$(MLX_DIR)
LIBFT_INC = -I. -I../$(MLX_DIR)


CC = cc
CFLAGS = -Wall -Wextra -Werror

# get_next_line.c, get_next_line_utils.cがgnlフォルダにあることを指定
vpath %.c gnl

all: $(NAME)

    # 修正点 4: minilibx-linuxを先にmakeしてlibmlx.aを作成する
    # 修正点 5: リンク時にMLXの静的ライブラリを含める
$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C ./Libft CFLAGS="$(CFLAGS) $(LIBFT_INC)"
	$(MAKE) -C ./printf
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(PRI) $(MLX_LIB) $(OPTION) -o $@

#Debug
debug: CFLAGS += -g -fsanitize=address
debug: re

# 修正点 6: コンパイル時のルールにヘッダーインクルードパスを追加
# mlx.hを見つけるために -I$(MLX_DIR) を追加
%.o: %.c
	@$(CC) $(CFLAGS) $(MAIN_INC) -c -o $@ $<

clean:
	$(MAKE) -C ./Libft clean
	$(MAKE) -C ./printf clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all