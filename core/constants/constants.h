/*!
 *  @brief     常量汇总
 *  @details   定义了软件运行时所需的常量信息，包括(图片、控件ID等)
 *  @author    wey
 *  @version   1.0
 *  @date      2017.12.11
 *  @warning
 *  @copyright NanJing RenGu.
 */
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constant {

/*日期*/
const char Date_Simple[] = "yyyy-MM-dd";

/*文件路径*/
const char AppShortName[] = "Rim";
const char ApplicationName[] = "ViewFrame";
const char Version[] = "1.1.0";

/*************************************************<配置文件config.ini>******************************************************/
//日志模块
const char LOG_LOG[] = "log";
const char LOG_LOG_RECORDFILE[] = "log2File";
const char LOG_LOG_LEVEL[] = "logLevel";

//数据库模块
const char DB_SETTING[] = "Database";
const char DB_TYPE[] = "Dbtype";
const char DB_HOST[] = "Hostname";
const char DB_DATABASE_NAME[] = "DatabaseName";
const char DB_USERNAME[] = "UserName";
const char DB_PASSWORD[] = "Password";
const char DB_PORT[] = "Port";

/*系统设置*/
const char SYSTEM_SETTING[] = "System";
const char SYSTEM_DEFAULT_SCHEMES[] = "defaultSchemes";
const char SYSTEM_USER_SCHEMES_NAME[] = "userSchemesName";
const char SYSTEM_LOCALE[] = "locale";
const char SYSTEM_STYLE[] = "stylesheet";
const char SYSTEM_FULLSCREEN[] = "fullscreen";
const char SYSTEM_TOPHINT[] = "tophint";
const char SYSTEM_MENUBAR[] = "menubar";
const char SYSTEM_LAYOUT[] = "systemlayout";


//布局
const char LAY_SETTING[] = "Layout";
const char LAY_GEOMETRY[] = "geometry";
const char LAY_WINDOWSTATE[] = "windowState";


/*************************************************</配置文件>******************************************************/


/*************************************************<插件信息>******************************************************/
/*
 * 插件命名按照【<PLUGIN>.<插件所属模块>.<插件名>】
 * 设置插件所属模块便于系统将同一模块下的插件进行整合处理
*/
const char PLUGIN_CORE[] = "Plugin.Core.Core";

const char PLUGIN_TASK_CONTROL[] = "Plugin.TaskControl.TaskControl";

const char PLUGIN_HEALTH_MANAGER[] = "Plugin.HealthManager.HealthManager";
const char PLUGIN_HEALTH_MANAGER_YW[] = "Plugin.HealthManager.HealthManager_YW";
const char PLUGIN_HEALTH_NETSTATE[] = "Plugin.HealthManager.NetState";
const char PLUGIN_HEALTH_RELOADCRCREPLY[] = "Plugin.HealthManager.ReloadCrcReply";
const char PLUGIN_HEALTH_RELOADRESULTREPLY[] = "Plugin.HealthManager.ReloadResultReply";

const char PLUGIN_RADIATION_SOURCE[] = "Plugin.DataDisplay.RadiationSource";
const char PLUGIN_ALL_PLUS[] = "Plugin.DataDisplay.AllPluse";
const char PLUGIN_MIDFREQ[] = "Plugin.DataDisplay.MidFreq";
const char PLUGIN_FREQ_SPECTRUM[] = "Plugin.DataDisplay.FreqSpectrum";
const char PLUGIN_LARGE_CAPACITY_DATA_STORAGE[] = "Plugin.DataDisplay.LargeCapacityDataStorage";
const char PLUGIN_IDENTIFICATION[] = "Plugin.DataDisplay.Identification";

const char PLUGIN_Tools_AutoTest[] = "Plugin.AutoTest.AutoTest";

/*************************************************</插件信息>******************************************************/


/*************************************************<工具插件信息>******************************************************/
/*
 * 插件命名按照【<TOOL>.<插件名>】
 * 设置插件所属模块便于系统将同一模块下的插件进行整合处理
*/
const char TOOL_SCREEN_SHOT[] = "TOOL.Screenshot";

/*************************************************</工具插件信息>******************************************************/

/*************************************************<工具栏>******************************************************/
//菜单栏
const char MENU_BAR[] = "MenuBar";

/*
 * 工具栏命名按照【<Menu>.<Group>.<工具栏名>】
*/
const char MENU_PROGRAM[]  = "Menu.Group.Program";
const char MENU_VIEW[]  = "Menu.Group.View";
const char MENU_SETTING[]  = "Menu.Group.Setting";
const char MENU_HELP[]     = "Menu.Group.Help";
const char DEFAULT_GROUP[] = "Menu.Default.Group";

/*
 * 菜单栏中action的Id命名按照【<Action>.<插件模块名>.<工具名>】
 * 请务必遵守，否则会影响快捷键(ShortcutSettings)的处理
*/

//MENU_PROGRAM 分组
const char PROGRAM_EXIT[] = "Action.Core.Exit";
const char SYSTEM_DELAY_SCREENSHOT[] = "Action.Core.DelayShot";
const char SYSTEM_NET_CONNECTION[] = "Action.Core.NetConnectionState";
const char SYSTEM_SYSTEM_SETTING[] = "Action.Core.SystemSetting";
const char SYSTEM_DATA_PLAYBACK[] = "Action.Core.DataPlayback";
const char SYSTEM_MAP_TOOLBAR[] = "Action.Core.MapToolBar";

//MENU_VIEW 分组
const char VIEW_MANAGER[] = "Action.Core.ViewManager";
const char IMPORT_VIEW[] = "Action.Core.ImportView";
const char EXPORT_VIEW[] = "Action.Core.ExportView";

//MENU_SETTING 分组
const char TOP_HINT[] = "Action.Core.TopHint";
const char FULL_SCREEN[] = "Action.Core.FullScreen";
const char CUSTOM_STYLE[] = "Action.Core.CustomStyle";
const char SYSTEM_LANGUAGE[] = "Action.Core.SystemLanguage";
const char SYSTEM_SHORTCUT[] = "Action.Core.ShortCut";
const char SYSTEM_SCREEN_SHOT[] = "Action.Core.ScreenShot";


//MENU_HELP 分组
const char TEC_SUPPORT[] = "Action.Core.TecSupport";
const char PLUGIN_DESC[] = "Action.Core.PluginDesc";
const char ABOUT_PROGRAM[] = "Action.Core.About";

/*************************************************</工具栏>******************************************************/

//右键菜单
const char MENU_ROUTE_TABLE_SERVER[] = "Menu.Route.Table.Server";             //路由表中服务器右键菜单

const char ACTION_ROUTE_SERVER_NEW[] = "Action_Route_Server_New";             //新建分组
const char ACTION_ROUTE_SERVER_DELETE[] = "Action_Route_Server_Delete";       //删除分组

const char MENU_ROUTE_TABLE_CLIENT[] = "Menu.Route.Table.Client";             //路由表中客户端右键菜单

const char ACTION_ROUTE_CLIENT_NEW[] = "Action_Route_Client_New";             //新建分组
const char ACTION_ROUTE_CLIENT_MOVE[] = "Action_Route_Client_Move";           //移动分组
const char ACTION_ROUTE_CLIENT_DELETE[] = "Action_Route_Clinet_Delete";       //删除分组


/******************************************<工具栏>*********************************************************/
const int TOOL_BAR_HEIGHT = 30;                         //工具栏固定高度
const int TOOL_WIDTH = 30;                              //工具按钮宽度
const int TOOL_HEIGHT = 30;                             //工具按钮高度

const char TOOL_MIN[] = "Tool_Min_Button";
const char TOOL_MAX[] = "Tool_Max_Button_True";
const char TOOL_CLOSE[] = "Tool_Close_Button";
const char TOOL_SETTING[] = "Tool_Setting_Button";

}

#endif // CONSTANTS_H
