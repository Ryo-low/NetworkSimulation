#pragma once
#include "Common.h"
#include "RGNUnit/RGNmake.h"
#include "OutputUnit/PajekFormat.h"

#include <iostream>
#include <chrono>
#define NEED_ARGS_NUM				3		// 必要最低限の引数の数
#define ARGS_NODE_NUM				1		// ノード指定の引数配列番号
#define ARGS_AVERAGE_LINK_NUM		2		// 平均リンク数指定の引数配列番号

#define SCALE_SPCIFY_ARGS			4		// ネットワークスケール指定時の引数の個数
#define ARGS_SCALE					3		// ネットワークスケール指定時の引数配列番号