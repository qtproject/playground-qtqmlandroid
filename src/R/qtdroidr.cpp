#include "qtdroidr_p.h"
#include <QtAndroidExtras/qandroidjniobject.h>
#include <QtAndroidExtras/qandroidjnienvironment.h>

QtDroidR::QtDroidR() :
    m_anim(0),
    m_animator(0),
    m_array(0),
    m_attr(0),
    m_boolean(0),
    m_color(0),
    m_dimen(0),
    m_drawable(0),
    m_fraction(0),
    m_id(0),
    m_integer(0),
    m_interpolator(0),
    m_layout(0),
    m_menu(0),
    m_mipmap(0),
    m_plurals(0),
    m_raw(0),
    m_string(0),
    m_style(0),
    m_styleable(0),
    m_transition(0),
    m_xml(0)
{
}

static QQmlPropertyMap *getFields(const char *className, QObject *parent)
{
    QQmlPropertyMap *map = new QQmlPropertyMap(parent);

    QAndroidJniEnvironment env;
    QAndroidJniObject anim(className);
    QAndroidJniObject clazz = anim.callObjectMethod("getClass", "()Ljava/lang/Class;");
    QAndroidJniObject fields = clazz.callObjectMethod("getFields", "()[Ljava/lang/reflect/Field;");

    jobjectArray array = fields.object<jobjectArray>();
    int length = env->GetArrayLength(array);
    for (int i = 0; i < length; ++i) {
        QAndroidJniObject field(env->GetObjectArrayElement(array, i));
        QString name = field.callObjectMethod("getName", "()Ljava/lang/String;").toString();
        jint value = field.callMethod<jint>("getInt", "(Ljava/lang/Object;)I", field.object());
        map->insert(name, value);
    }
    return map;
}

QQmlPropertyMap *QtDroidR::anim()
{
    if (!m_anim)
        m_anim = getFields("android/R$anim", this);
    return m_anim;
}

QQmlPropertyMap *QtDroidR::animator()
{
    if (!m_animator)
        m_animator = getFields("android/R$animator", this);
    return m_animator;
}

QQmlPropertyMap *QtDroidR::array()
{
    if (!m_array)
        m_array = getFields("android/R$array", this);
    return m_array;
}

QQmlPropertyMap *QtDroidR::attr()
{
    if (!m_attr)
        m_attr = getFields("android/R$attr", this);
    return m_attr;
}

QQmlPropertyMap *QtDroidR::boolean()
{
    if (!m_boolean)
        m_boolean = getFields("android/R$boolean", this);
    return m_boolean;
}

QQmlPropertyMap *QtDroidR::color()
{
    if (!m_color)
        m_color = getFields("android/R$color", this);
    return m_color;
}

QQmlPropertyMap *QtDroidR::dimen()
{
    if (!m_dimen)
        m_dimen = getFields("android/R$dimen", this);
    return m_dimen;
}

QQmlPropertyMap *QtDroidR::drawable()
{
    if (!m_drawable)
        m_drawable = getFields("android/R$drawable", this);
    return m_drawable;
}

QQmlPropertyMap *QtDroidR::fraction()
{
    if (!m_fraction)
        m_fraction = getFields("android/R$fraction", this);
    return m_fraction;
}

QQmlPropertyMap *QtDroidR::id()
{
    if (!m_id)
        m_id = getFields("android/R$id", this);
    return m_id;
}

QQmlPropertyMap *QtDroidR::integer()
{
    if (!m_integer)
        m_integer = getFields("android/R$integer", this);
    return m_integer;
}

QQmlPropertyMap *QtDroidR::interpolator()
{
    if (!m_interpolator)
        m_interpolator = getFields("android/R$interpolator", this);
    return m_interpolator;
}

QQmlPropertyMap *QtDroidR::layout()
{
    if (!m_layout)
        m_layout = getFields("android/R$layout", this);
    return m_layout;
}

QQmlPropertyMap *QtDroidR::menu()
{
    if (!m_menu)
        m_menu = getFields("android/R$menu", this);
    return m_menu;
}

QQmlPropertyMap *QtDroidR::mipmap()
{
    if (!m_mipmap)
        m_mipmap = getFields("android/R$mipmap", this);
    return m_mipmap;
}

QQmlPropertyMap *QtDroidR::plurals()
{
    if (!m_plurals)
        m_plurals = getFields("android/R$plurals", this);
    return m_plurals;
}

QQmlPropertyMap *QtDroidR::raw()
{
    if (!m_raw)
        m_raw = getFields("android/R$raw", this);
    return m_raw;
}

QQmlPropertyMap *QtDroidR::string()
{
    if (!m_string)
        m_string = getFields("android/R$string", this);
    return m_string;
}

QQmlPropertyMap *QtDroidR::style()
{
    if (!m_style)
        m_style = getFields("android/R$style", this);
    return m_style;
}

QQmlPropertyMap *QtDroidR::styleable()
{
    if (!m_styleable)
        m_styleable = getFields("android/R$styleable", this);
    return m_styleable;
}

QQmlPropertyMap *QtDroidR::transition()
{
    if (!m_transition)
        m_transition = getFields("android/R$transition", this);
    return m_transition;
}

QQmlPropertyMap *QtDroidR::xml()
{
    if (!m_xml)
        m_xml = getFields("android/R$xml", this);
    return m_xml;
}

QObject *QtDroidR::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new QtDroidR;
}
