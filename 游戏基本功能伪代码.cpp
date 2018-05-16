Procedure 游戏界面的生成 is
	//公共变量暂时先放在这里定义，以便所有的函数能够访问该变量 
	declare 关卡数 as scalar
	declare 角色名 as string 
	declare 游戏状态 as bool 
	
	关卡数 = 1 
	游戏状态 = true 	
	loop while 关卡数 <= 3
		执行 关卡界面的生成
		关卡数++ 
	end loop

end 游戏界面的生成

Procedure 关卡界面的生成
	展示游戏剧情界面 
	执行 场景界面的生成 
	if 游戏状态 = false then
		终止关卡界面的运行 
		执行 游戏结束界面的生成 
	end if 
end 关卡界面的生成 

Procedure 场景界面的生成
	//要用到的公共变量先暂时放在这里面定义
	declare 角色等级 as scalar
	declare 游戏分数 as scalar
	declare 角色速度 as scalar
	declare 离敌方距离 as scalar
	declare 玩家的位置 as struct
	declare 角色体力 as scalar
	declare 最大体力 as scalar 
	declare 视野范围 as scalar 
	declare 当天状态 as string 
	declare 关卡时间 as scalar 
	declare 关卡经过时间 as scalar 
	declare 装备总量 as scalar
	declare 装备箱 as list 
	declare 背包已有物品 as list 
	
	执行 地图及装备的生成 
	执行 游戏状态条的生成 
end 场景界面的生成
 
Procedure 游戏状态条的生成 
	//游戏状态条角色的信息 
	print "角色"
	输出角色对应的图像 
	print "等级"
	print "分数"
	print "速度"
	print "离敌方距离"
	//游戏状态条关卡的信息 
	print "关卡" + 关卡数 
	输出上下左右对应的图像
	输出背包轮廓的图像 
	
	//对应Unity3d里面的Update()函数，系统会自动执行 
	loop while 游戏状态 == true 
		删除掉原来已经输出过的属性 
		获取实时属性 
		//所有输出都输出到游戏状态条上 
		//游戏状态条角色的信息
		print 角色名 
		print 角色等级
		print 游戏分数
		print 角色速度
		print 角色体力 
		//游戏状态条关卡的信息 
		print 关卡时间-关卡经过时间		//关卡剩余时间 
		print 当天状态
		//游戏状态条 
		输出背包内已有的物品图像 
	end loop
end 游戏状态条的生成  

Procedure 地图及装备的生成 
	执行 地图的生成 
	//对应Unity3d里面的Update()函数，系统会自动执行 
	loop while 游戏状态 == true 
		执行 装备的刷新 
	end loop
end 地图及装备的生成  

Procedure 地图的生成
	declare 地图块列表 as list			//列表内存放着包括地面块，墙体块以及其它障碍块，出口块等信息 
	declare 地图长 as scalar
	declare 地图宽 as scalar
	declare 障碍块长度 as scalar		//这里障碍块长度和宽度相等，方便人物上下行走速度的统一以及为了游戏的美观 
	//由于本游戏的特殊性，我们可以将一整个迷宫划分成若干个大的迷宫块，大的迷宫块有一条出路，并且大的迷宫块里面也有一条出路 
	declare 大块迷宫 as array			//n*n二维数组
	
	
	//declare i as scalar
	//declare j as scalar
	//i = 0;
	//loop while i < 地图长/障碍块长度
	//	j = 0;
	//	loop while j < 地图宽/障碍块长度 
	//		在游戏界面(i*障碍块长度,j*障碍块长度)处生成地面 
	//		j++
	//	end loop
	//	i++ 
	//end loop 
	将地图中所有的迷宫块都铺上地砖 
	
	在大块之间从左上角、左下角、右上角、右下角这四个点选择一个点作为起点
	//模拟走一遍迷宫，终点为大块迷宫边缘处某一点，至少走(n+1)步到达终点。 
	执行 迷宫的行走			
	在大块迷宫内部随机生成其它障碍物 
	设置地图的遮罩层，将整个地图的遮罩层亮度调为0 
	在地图中没有障碍物的地方生成装备 
end  地图的生成




Procedure 人类以及狼人的行走 
	人类附近半径为 视野范围 的圆内，调高其附近遮罩层的亮度 
	//在移动界面分别点击了类似于↑↓←→的按钮 
	if 点击↑ then
		if 玩家未触碰到障碍物 then 
			玩家的位置.y位置 += 角色移动速度*间隔时间	//间隔时间在Unit3d中用time.deltatime表示
		else
			角色不移动 
		end if
	else if 点击↓ then
		if 玩家未触碰到障碍物 then 
			玩家的位置.y位置 -= 角色移动速度*间隔时间
		else
			角色不移动 
		end if
	else if 点击← then
		if 玩家未触碰到障碍物 then
			玩家的位置.x位置 -= 角色移动速度*间隔时间
		else
			角色不移动 
		end if
	else if 点击→ then
		if 玩家未触碰到障碍物 then
			玩家的位置.x位置 += 角色移动速度*间隔时间
		else
			角色不移动  
		end if
	else
		角色不移动 
	end if 
	
	在游戏界面中显示角色对应的图像并改变人类附近遮罩层的在游戏界面位置 
	角色体力 = 角色体力 - 体力消耗速度 * 间隔时间; 
	
	if 角色名=="狼人" and 角色体力 == 0
		游戏状态 = false 
	end if 
	
end 人类以及狼人的行走 

Procedure 人类以及狼人的交互
	if 角色名 == "人类" then					//狼人刚好触碰到人类，Unity3d可以用刚体碰撞实现
		if 狼人触碰到了人类	
			关卡界面及地图界面停止					 
			游戏状态 = false 
		end if
	else										// 角色名 == "狼人" then 
		if 狼人触碰到了人类	
			角色体力 += (最大体力-角色体力)*Random(0.2,0.8) 				 
		end if
	end if
	
end 人类以及狼人的交互 


Procedure 玩家与装备的交互
	执行 玩家拾取装备
	执行 玩家丢弃装备 
	执行 玩家使用装备 
end 玩家与装备的交互 

Procedure 玩家拾取装备
	if 玩家的位置刚好在道具位置范围之内	then	//玩家刚好触碰到道具，Unity3d可以用刚体碰撞实现
		if 装备箱.size <= 装备总量 then
			在该地方的装备消失
			装备箱.add(该地方的装备)			//向装备箱增加一个装备 
		else
			装备仍然保留在原地 
		end if
	end if
end 玩家拾取装备 

Procedure 玩家丢弃装备
	if 点击丢弃按钮 then
		该装备丢失
	else
		保留该装备 
	end if 
	
end 玩家丢弃装备
	
Procedure 玩家使用装备
	//对应游戏界面状态条点击编号，使用装备  
	if 玩家点击游戏状态条装备部分的对应装备 then
		提取该装备的信息 
		declare 是否删除该装备 as bool
		是否删除该装备 = true 
		if 该装备是猎枪 then
			//装备具体功能待定
			if 角色名 == "人类" then
				if 人类所在区域内存在狼人 then
					人类所在区域内的狼人消失
				else
					是否删除该装备 = false
				end if
			else 								//角色名 == 狼人 then
				if 狼人附近是否存在人类 then
					狼人附近的人类消失
					角色体力 += (最大体力-角色体力)*Random(0.2,0.8) 
				else
					是否删除该装备 = false
				end if
			end if
		else if 该装备是防狼喷雾 then 
			//装备具体功效待定
			狼人找到玩家的概率减小 
			坚持10秒钟
			狼人找到玩家的概率增大 
		else if 该装备是铲子 then
			if 玩家站在障碍物附近并且玩家朝向障碍物 then
				玩家朝向的障碍物消失 
			else	
				是否删除该装备 = false				//该装备没有使用成功 
			end if
		else if 该装备是照明弹 then
			将整个地图的遮罩层亮度调为1
			等待3秒钟 
			将整个地图的遮罩层亮度调为0 
		else if 该装备是隐身衣 then
			地图界面中角色画面的透明度调为0.9 
			对于敌方来说角色的坐标轴位置消失 
			坚持10秒钟 
			对于敌方来说角色的坐标轴位置重现 
			地图界面中角色画面的透明度调为0 
		else if 该装备是傀儡 then
			//装备功能待定
			地图界面中新生成一个人物，其行动路线和原始人类行动路线相同 
		else if 该装备是时光药水 then
			//装备的功能待定
			关卡时间 += 60 
		else if 该装备是体力药水 then
			角色体力 += (最大体力-角色体力)*Random(0,1)
		else if 该装备是手电筒 then
			视野范围 += 1 
		end if
		if 是否删除该装备 == true then
			装备箱.delete(该装备) 	
		end if	 
	end if
	
end 玩家使用装备 


