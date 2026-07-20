const fs = require('fs');
const path = require('path');

// 💡 请根据实际情况修改你的 C++ 头文件路径
const filePath = path.join(__dirname, 'src/mod_assistant.h');

// 1. 将你的 sed 规则完美映射为 JavaScript 的中英文对照字典
const translationMap = {
    '"I want heirlooms"': '"我想要传家宝"',
    '"I want weapons"': '"我想要武器"',
    '"I want armor"': '"我想要护甲"',
    '"I want something else"': '"我想要其他东西"',
    '"I want glyphs"': '"我想要雕文"',
    '"I want some major glyphs"': '"我想要一些大雕文"',
    '"I want some minor glyphs"': '"我想要一些小雕文"',
    '"I want gems"': '"我想要宝石"',
    '"I want some meta gems"': '"我想要一些多彩宝石"',
    '"I want some red gems"': '"我想要一些红色宝石"',
    '"I want some blue gems"': '"我想要一些蓝色宝石"',
    '"I want some yellow gems"': '"我想要一些黄色宝石"',
    '"I want some purple gems"': '"我想要一些紫色宝石"',
    '"I want some green gems"': '"我想要一些绿色宝石"',
    '"I want some orange gems"': '"我想要一些橙色宝石"',
    '"I want elixirs"': '"我想要药剂"',
    '"I want some battle elixirs"': '"我想要一些战斗药剂"',
    '"I want some guardian elixirs"': '"我想要一些守护药剂"',
    '"I want some flasks"': '"我想要一些合剂"',
    '"I want food"': '"我想要食物"',
    '"I want enchants"': '"我想要附魔"',
    '"I want weapon enchants"': '"我想要武器附魔"',
    '"I want head enchants"': '"我想要头部附魔"',
    '"I want shoulder enchants"': '"我想要肩部附魔"',
    '"I want chest enchants"': '"我想要胸部附魔"',
    '"I want bracer enchants"': '"我想要护腕附魔"',
    '"I want glove enchants"': '"我想要手套附魔"',
    '"I want belt enchants"': '"我想要腰带附魔"',
    '"I want leg enchants"': '"我想要腿部附魔"',
    '"I want boots enchants"': '"我想要鞋子附魔"',
    '"I want cloak enchants"': '"我想要披风附魔"',
    '"I want shield enchants"': '"我想要盾牌附魔"',
    '"I want containers"': '"我想要容器(背包)"',
    '"I want utilities"': '"我想要实用工具"',
    '"I want to change my name"': '"我想修改我的名字"',
    '"I want to change my appearance"': '"我想修改我的外貌"',
    '"I want to change my race"': '"我想修改我的种族"',
    '"I want to change my faction"': '"我想修改我的阵营"',
    '"You must complete the previously activated feature before trying to perform another."': '"您必须完成之前激活的功能，然后才能尝试执行另一项功能。"',
    '"You can now log out to continue using the activated feature."': '"您现在可以小退(登出)来继续使用已激活的功能。"',
    '"I want to unlock flight paths"': '"我想要解锁飞行点"',
    '"Kalimdor & Eastern Kingdoms"': '"卡利姆多 ＆ 东部王国"', // 去掉了 sed 环境下的转义斜杠
    '"Outland"': '"外域"',
    '"Northrend"': '"诺森德"',
    '"I want help with my professions"': '"我需要专业技能方面的帮助"',
    '"I want help with my skill in"': '"我需要提升这项技能："',
    '"First Aid"': '"急救"',
    '"Blacksmithing"': '"锻造"',
    '"Leatherworking"': '"制皮"',
    '"Alchemy"': '"炼金术"',
    '"Herbalism"': '"草药学"',
    '"Cooking"': '"烹饪"',
    '"Mining"': '"采矿"',
    '"Tailoring"': '"裁缝"',
    '"Engineering"': '"工程学"',
    '"Enchanting"': '"附魔"',
    '"Fishing"': '"钓鱼"',
    '"Skinning"': '"剥皮"',
    '"Inscription"': '"铭文"',
    '"Jewelcrafting"': '"珠宝加工"',
    '"I want to reset instances"': '"我想要重置副本"',
    '"I want to reset heroic dungeons"': '"我想要重置英雄地下城"',
    '"I want to reset raids"': '"我想要重置团队副本"',
    '"Just for me"': '"仅针对我自己"',
    '"For my entire group"': '"针对我整个队伍/团队"', // 去掉了旧 sed 用于规避替换分隔符的斜杠
    '"All heroic dungeons have been reset."': '"所有英雄地下城已重置。"',
    '"All of your groups heroic dungeons have been reset."': '"你队伍的所有英雄地下城已重置。"',
    '"All raids have been reset."': '"所有团队副本已重置。"',
    '"All of your groups raids have been reset."': '"你队伍的所有团队副本已重置。"',
    '"Do you wish to continue the transaction?"': '"你想继续这次交易吗？"', // 去掉了 sed 的问号转义
    '"Previous Page"': '"上一页"'
};

// 2. 检查文件是否存在
if (!fs.existsSync(filePath)) {
    console.error(`❌ 错误：找不到文件，请确认路径是否正确: ${filePath}`);
    process.exit(1);
}

try {
    // 3. 读取目标 C++ 头文件
    let content = fs.readFileSync(filePath, 'utf8');
    let replaceCount = 0;

    // 4. 遍历字典，安全地全局替换
    Object.keys(translationMap).forEach((englishKey) => {
        if (content.includes(englishKey)) {
            // 对英文中的正则表达式特殊符号（如问号、括号等）进行自动安全转义，防止正则引擎误判
            const safeRegexStr = englishKey.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&');
            const regex = new RegExp(safeRegexStr, 'g');
            
            content = content.replace(regex, translationMap[englishKey]);
            replaceCount++;
        }
    });

    // 5. 将汉化后的内容写回文件
    fs.writeFileSync(filePath, content, 'utf8');
    console.log(`🎉 汉化成功！已同时成功替换了 ${replaceCount} 处内置菜单。`);

} catch (error) {
    console.error('❌ 执行汉化脚本时发生错误:', error.message);
}


// 终端中运行  node translate_assistant.js