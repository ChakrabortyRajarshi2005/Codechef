Multiple Change Sum
Given an array 
A
A of length 
N
N.

There is an integer variable 
X
X and a score 
S
S. Initially, 
X
=
0
X=0 and 
S
=
0
S=0.

You play the following single-player game on the array 
A
A for the next 
N
N seconds:

In the 
t
t-th second (
1
≤
t
≤
N
1≤t≤N), you may choose any index 
i
i such that 
1
≤
i
≤
N
1≤i≤N and 
t
∣
i
t∣i (i.e., 
i
i is a multiple of 
t
t).
Then, update the score 
S
S as follows: 
S
=
S
+
∣
X
−
A
i
∣
S=S+∣X−A 
i
​
 ∣.
Then, set 
X
=
A
i
X=A 
i
​
 .
Alternatively, you can also choose to do nothing in the 
t
t-th second (both 
X
X and 
S
S remain unchanged).
Define 
f
(
A
)
f(A) to be the maximum possible final score 
S
S that can be achieved by playing the game optimally.
// 2025.09.20 at 02:08:54 BST
import java.io.*
import kotlin.system.measureTimeMillis
import java.util.TreeMap
import java.util.TreeSet
import kotlin.math.*
import kotlin.random.Random
import kotlin.random.nextInt

//All typealias that I use
typealias pii = Pair<Int,Int>
typealias pll = Pair<Long,Long> //stupid R/Gac two-sided recognitions
typealias ints = IntArray
typealias longs = LongArray
typealias bools = BooleanArray
// 1. Modded
fun Int.adjust():Int{ if(this >= p){ return this  - p }else if (this < 0){ return this + p };return this }
fun Int.snap():Int{ return if(this >= p){ this - p } else this }
infix fun Int.mm(b:Int):Int{ return ((this.toLong() * b) % p).toInt() }
infix fun Int.mp(b:Int):Int{ val ans = this + b;return if(ans >= p) ans - p else ans }
infix fun Int.ms(b:Int):Int{ val ans = this - b;return if(ans < 0) ans + p else ans }
fun Long.modded():Int = (this % p).toInt().adjust()
fun Int.inverse():Int = intPow(this,p-2)
fun Int.additiveInverse():Int = if(this == 0) 0 else p - this
infix fun Int.modDivide(b:Int):Int{ return this mm (b.inverse()) }
fun intPow(x:Int, e:Int):Int{
    var x = x; var e = e ; var ret = 1
    while(e > 0){
        if(e and 1 == 1) ret = ret mm x
        x = x mm x
        e = e shr 1
    }
    return ret
}
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
//3. hard to write stuff
val mint get() = mutableListOf<Int>()
val mong get() = mutableListOf<Long>()
val mchar get() = mutableListOf<Char>()
fun IntArray.minindex() = this.indexOf(this.minOrNull()!!)
fun IntArray.maxindex() = this.indexOf(this.maxOrNull()!!)
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.concatToString()
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
@JvmName("concaString")
fun List<String>.conca():String = this.joinToString("")
//5. Simple calculations
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val BooleanArray.chiarray:IntArray get() = IntArray(this.size){this[it].chi}
val Char.code :Int get() = this.toInt() -  'a'.toInt()
fun order(a:Int, b:Int):Pair<Int,Int> = Pair(minOf(a,b), maxOf(a,b))
val String.size get() = this.length
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)
fun Long.has(i:Int):Boolean = (this and (1L shl i) != 0L)
fun dist(a: Int, b: Int): Int = if(a > b) a-b else b - a
fun dist(a: Long, b: Long): Long = if(a > b) a-b else b - a //chatgpt is right this is faster
//8 TIME
inline fun TIME(f:()->Unit){
    val t = measureTimeMillis{ f() }
    println("$t ms")
}
//9 rand
fun rand(x:Int) = Random.nextInt(x)
fun rand(x:IntRange) = Random.nextInt(x)
inline fun assert(x:Boolean,act:()->Any = {}){ if(!x) error(act())}
const val interactive = false
//11 Quick output
val YES:Unit get() = put("YES")
val NO:Unit get() = put("NO")
//12 Array put
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
infix fun Long.up(other:Long):Long = if(other > this) other else this
infix fun Long.down(other:Long):Long = if(other < this) other else this
infix fun Int.up(other:Int):Int = if(other > this) other else this
infix fun Int.down(other:Int):Int = if(other < this) other else this
fun LongArray.up(i:Int, v:Long){ if(v > this[i]) this[i] =v  }
fun LongArray.down(i:Int, v:Long){ if(v < this[i]) this[i] = v}
fun IntArray.up(i:Int, v:Int){ if(v > this[i]) this[i] = v }
fun IntArray.down(i:Int, v:Int){ if(v< this[i]) this[i]= v }
@Target(AnnotationTarget.FUNCTION)  @Retention(AnnotationRetention.RUNTIME)  annotation class show
object Reader{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    var lastTC:String = ""
    private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)
    private val char: Char
        get() {
            if(interactive){
                val c = System.`in`.read()
                return if(c == -1) NC else c.toChar()
            }
            while (bId == size) {
                size = IN.read(buf)
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        } // Must terminate input process after reading two NCs
    fun nextLong(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            if(c == NC) throw Error("Bad Input")
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextString():String{
        val ret = StringBuilder()
        while (true){
            c = char
            if(c == NC) throw Error("Bad Input")
            if(!isWhitespace(c)){ break}
        }
        do{
            ret.append(c)
            c = char
        }while(!isWhitespace(c))
        return ret.toString()
    }
    private fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == NC
    }
    fun flush(){
        OUT.flush()
    }
    fun takeString(str:String){
        lastTC = str
        IN = BufferedInputStream(lastTC.byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){
    Reader.OUT.println(aa)
    if(interactive){ Reader.flush()}
}
fun put(vararg x:Any){
    val count = x.size
    for((pt, c) in x.withIndex()){
        Reader.OUT.print(c)
        if(pt + 1 != count) Reader.OUT.print(" ")
    }
    Reader.OUT.print("\n")
    if(interactive){ Reader.flush()}
}
fun done() = Reader.OUT.close()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE){IntArray(1000000000);error("Input Overflow")};return ans.toInt() }
val getlong:Long get() = Reader.nextLong()
val getstr:String get() = Reader.nextString()
fun getline(n:Int):IntArray = IntArray(n){getint}
fun getlineL(n:Int):LongArray = LongArray(n){getlong}
fun subformat(a:Any?):String{ // for not a collection
    return when(a) {
        null -> "null"
        is Iterable<*> -> a.joinToString(" ")
        is BooleanArray -> a.joinToString("") { if (it) "1" else "0" }
        is IntArray -> a.joinToString(" ")
        is LongArray -> a.joinToString(" ")
        else -> a.toString()
    } }
fun format(a:Any?):String { return when(a) {
    null -> "null"
    is BooleanArray -> a.joinToString("") { if (it) "1" else "0" }
    is Array<*> -> "\n"+a.joinToString("\n"){subformat(it)}
    else -> subformat(a)
} }
var dmark = -1
infix fun Any.dei(a:Any?){
    dmark++ ; debug()
    println("<${dmark}>   $this : ${format(a)}")
}
const val just = " "
fun keepimport(){ val st1 = TreeSet<Int>(); val st2 = TreeMap<Int,Int>(); val c = (3).absoluteValue}
inline fun cases(onecase:()->Unit){
    val count = if(singleCase) 1 else getint
    repeat(count){ onecase() }
}
fun share(aa:Any){solve.fakein.append(format(aa) + '\n')}
fun share(vararg x:Any){
    val count = x.size
    for((pt, c) in x.withIndex()){
        solve.fakein.append(format(c))
        if(pt + 1 != count) solve.fakein.append(' ')
    }
    solve.fakein.append('\n')
}
enum class solveMode { real, rand, tc }
object solve{
    private var randCount = 100
    private var mode:solveMode = solveMode.real
    private var tcNum:Int = 0
    val fakein = StringBuilder()
    var rand:()->Unit = {}
    private var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    private var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        if(mode != solveMode.real) tn = System.currentTimeMillis()
        repeat(t){
            if(mode != solveMode.real){
                if(mode == solveMode.tc){
                    TC[tcNum]?.let { it() }
                }else if(mode == solveMode.rand){
                    rand()
                }
                val tcstr = fakein.toString()
                fakein.clear()
                println("New Case ")
                println(tcstr.take(80))
                println("...")
                Reader.takeString(tcstr)
            }
            onecase()
        }
        if(mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            put("Time $dt ms ")
        }
    }
    fun rand(a:()->Unit){
        this.rand = a
    }
    fun tc(id:Int = 0,a:()->Unit){
        TC[id] = a
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(count:Int = 100){
        this.randCount = count
        this.mode = solveMode.rand
    }
}
fun debug(){}



interface monoid<M>{
    val id:M
    fun op(a:M, b:M):M
    fun reduce(a:Iterable<M>):M{
        var ret = id
        for(v in a) ret = op(ret, v)
        return ret
    }
    fun raise(a:M, e:Int):M{
        var x = a; var e = e ; var ret = id
        while(e > 0){
            if(e and 1 == 1) ret = op(ret,x)
            x = op(x,x)
            e = e shr 1
        }
        return ret
    }
    operator fun M.times(a:M):M = op(this,a)
}
fun monoid<Int>.reduce(a:IntArray):Int{
    var ret = id
    for(v in a) ret = op(ret, v)
    return ret
}
fun monoid<Long>.reduce(a:LongArray):Long{
    var ret = id
    for(v in a) ret = op(ret, v)
    return ret
}
interface idemMonoid<M>:monoid<M>{
    override val id:M
    override fun op(a:M, b:M):M
}
object IntMin:idemMonoid<Int>{
    override val id: Int = plarge
    override fun op(a: Int, b: Int): Int = minOf(a,b)
}
object IntMax:idemMonoid<Int>{
    override val id: Int = nlarge
    override fun op(a: Int, b: Int): Int = maxOf(a,b)
}
object LongMin:idemMonoid<Long>{
    override val id: Long = phuge
    override fun op(a: Long, b: Long): Long = minOf(a,b)
}
object LongMax:idemMonoid<Long>{
    override val id: Long = nhuge
    override fun op(a: Long, b: Long): Long = maxOf(a,b)
}

object IntAnd:idemMonoid<Int>{
    override val id: Int = -1
    override fun op(a: Int, b: Int): Int  = a and b
}
object IntOr:idemMonoid<Int>{
    override val id: Int = 0
    override fun op(a: Int, b: Int): Int  = a or b
}

class item(var w00:Long, var w01:Long, var w10:Long, var w11:Long){
    fun copyFrom(other:item){
        this.w00 = other.w00
        this.w01 = other.w01
        this.w10 = other.w10
        this.w11 = other.w11
    }
}
object merge:monoid<item>{
    override val id:item
        get() = item(0L, nhuge, nhuge, 0L)

    override fun op(a:item, b:item):item {
        val nw00 = maxOf(a.w00 + b.w00, a.w01 + b.w10)
        val nw01 = maxOf(a.w00 + b.w01 , a.w01 + b.w11)
        val nw10 = maxOf(a.w10 + b.w00, a.w11 + b.w10)
        val nw11 = maxOf(a.w10 + b.w01, a.w11 + b.w11)
        return item(nw00, nw01, nw10,nw11)
    }
    fun construct(s0:Int, s1:Int, t0:Int, t1:Int):item{
        return item(dist(s0, t0).toLong(), dist(s0, t1).toLong(), dist(s1,t0).toLong(), dist(s1,t1).toLong())
    }
}


//template developments need work
private typealias gSeg_M = item
private typealias gSeg_MA = Array<item>
private typealias gSeg_struct = merge

class gSeg (val start:gSeg_MA){
    val startn = start.size //Contract: anything outsied of 0 until startn must stay identity
    fun op(a:gSeg_M, b:gSeg_M):gSeg_M = gSeg_struct.op(a,b)
    val id:gSeg_M get() = gSeg_struct.id
    val N = if(start.size >= 2) (start.size - 1).takeHighestOneBit() shl 1 else start.size
    val level = 31 - N.countLeadingZeroBits()
    val arr = gSeg_MA(2 * N){if(it in N until N +start.size) start[it - N] else id}
    fun update(i:Int){ arr[i].copyFrom(op(arr[i shl 1], arr[(i shl 1) + 1]))}
    constructor(n:Int, v:gSeg_M = gSeg_struct.id):this(gSeg_MA(n){v})
    init{
        for(i in N-1 downTo 1) update(i)
    }
    fun updatePath(i:Int){
        var now = i + N
        while(now > 1){ now = now shr 1 ; update(now)}
    }
    fun set(i:Int, v:gSeg_M){ arr[i+N].copyFrom(v); updatePath(i)}
    fun add(i:Int, v:gSeg_M){ arr[i+N].copyFrom(op(arr[i+N], v)); updatePath(i)}
    fun query(l:Int, r:Int): gSeg_M {
        var l = maxOf(0, l) + N; var r = minOf(r, N-1) + N; if(l > r) return id
        var left = id ; var right = id
        while(l <= r){
            if(l and 1 == 1) left = op(left, arr[l++])
            if(r and 1 == 0) right = op(arr[r--], right)
            l = l shr 1; r = r shr 1
        }
        return op(left, right)
    }
    inline fun rightExtendFirstTrue(l:Int, ok:(gSeg_M)->Boolean):Pair<Int, gSeg_M>?{ // return the first r, where l <= r < startn such that the composition is true
        var now = id
        var lnow = l + N
        var rnow = 2 * N - 1
        while(lnow <= rnow){
            if(lnow and 1 == 1){
                val attempt = op(now,arr[lnow])
                if(!ok(attempt)){
                    now = attempt
                    lnow++
                }else{
                    var node = lnow
                    while(node < N){
                        node = node shl 1
                        val attempt = op(now,arr[node])
                        if(!ok(attempt)){
                            now = attempt
                            node++
                        }
                    }
                    return (node - N) to op(now, arr[node])
                }
            }
            lnow = lnow shr 1
            rnow = rnow shr 1
        }
        return null
    }
    inline fun rightExtendLastTrue(l:Int, ok:(gSeg_M)->Boolean):Pair<Int,gSeg_M>?{
        var now = id
        var lnow = l + N
        var rnow = 2 * N - 1
        while(lnow <= rnow){
            if(lnow and 1 == 1){
                val attempt = op(now,arr[lnow])
                if(ok(attempt)){
                    now = attempt
                    lnow++
                }else{
                    var node = lnow
                    while(node < N){
                        node = node shl 1
                        val attempt = op(now,arr[node])
                        if(ok(attempt)){
                            now = attempt
                            node++
                        }
                    }
                    if(node-N == l) return null
                    return (node - N - 1) to now
                }
            }
            lnow = lnow shr 1
            rnow = rnow shr 1
        }
        return (startn-1) to now
    }
}
class multiset(val st: TreeMap<Int, Int> = TreeMap()):MutableMap<Int,Int> by st {
    constructor(a:IntArray):this(){
        addall(a)
    }
    var multisize = 0
    operator fun contains(v:Int):Boolean{
        return st.contains(v)
    }
    fun addall(a:IntArray){
        for(v in a) addone(v)
    }
    fun addall(a:List<Int>){
        for(v in a) addone(v)
    }
    fun addone(v:Int){
        multisize ++
        st[v] = st.getOrDefault(v,0) + 1
    }
    fun removeone(v:Int):Boolean{
        val new = st.getOrDefault(v,0) - 1
        if(new == -1) return false
        if(new > 0) st[v] = new else st.remove(v)
        multisize --
        return true
    }
    fun pollLast():Int {
        val a = st.lastKey()
        removeone(a)
        return a
    }
    fun pollFirst():Int{
        val a = st.firstKey()
        removeone(a)
        return a
    }
    fun last():Int = st.lastKey()
    fun first():Int = st.firstKey()
    fun makelist():MutableList<Int>{
        val ret = mutableListOf<Int>()
        for((k,v) in st){
            repeat(v){
                ret.add(k)
            }
        }
        return ret
    }
}

object sieve{
    const val sieveMx = 200005
    val primeOf = IntArray(sieveMx + 1)
    var primeCounter = 0
    val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(Math.log(sieveMx.toDouble()) -4)).toInt() +3)
    val primes = IntArray(primeUpperBound)
    var sieveCalculated = false
    val nextPrime = IntArray(sieveMx+1)
    val nextPrimePower = IntArray(sieveMx+1)
    val afterPrimePowerDivison = IntArray(sieveMx+1)
    var mobius = IntArray(0)
    var fstart = IntArray(0)
    var factor = IntArray(0)

    var factors:List<MutableList<Int>> = mutableListOf()

    fun calculateSieveFast(){
        if(sieveCalculated){
            return
        }
        primeOf[0] = -1
        sieveCalculated = true
        for(i in 2..sieveMx){
            if(primeOf[i] == 0 ){
                primeOf[i] = i
                primes[primeCounter] = i
                primeCounter += 1
            }
            for(j in 0 until primeCounter){
                val p = primes[j]
                val pd = p * i
                if(p <= i && pd <= sieveMx){
                    primeOf[pd] = p
                }else{
                    break
                }
            }
        }
    }
    fun preparePrimePower(){
        nextPrime[1] = -1
        nextPrimePower[1] = -1
        afterPrimePowerDivison[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            val new = i / p
            nextPrime[i] = p
            if(nextPrime[new] == p){
                nextPrimePower[i] = nextPrimePower[new]
                afterPrimePowerDivison[i] = afterPrimePowerDivison[new]
            }else{
                afterPrimePowerDivison[i] = new
            }
            nextPrimePower[i] += 1
        }
    }
    fun primeID():Pair<IntArray,IntArray>{
        assert(sieveCalculated)
        var now =0
        val primes = IntArray(primeCounter)
        val id = IntArray(sieveMx) {
            if (it > 0 && primeOf[it] == it) {
                primes[now] = it
                return@IntArray now++
            } else -1}
        return Pair(primes,id)
    }
    fun prepareFactor(){
        val fcount = IntArray(sieveMx +1)
        fcount[1] = 1
        var total = 1
        for(i in 2..sieveMx){
            fcount[i] = fcount[afterPrimePowerDivison[i]] * (nextPrimePower[i] + 1)
            total += fcount[i]
        }
        factor = IntArray(total)
        fstart = IntArray(sieveMx+1)
        factor[0] = 1

        for(i in 2..sieveMx){
            fstart[i] = fstart[i-1] + fcount[i-1]
            val prev = i / nextPrime[i]
            val pcount = fcount[afterPrimePowerDivison[i]]
            factor.copyInto(factor,fstart[i],fstart[prev],fstart[prev+1])
            for(x in (fstart[i] + fcount[i] - 2 * pcount) until (fstart[i] + fcount[i] - pcount)){
                factor[x+pcount] = factor[x] * nextPrime[i]
            }
        }
        for(i in 2..sieveMx){
            factor.sort(fromIndex = fstart[i], toIndex = fstart[i] + fcount[i])
        }
    }
    fun calculateMobius(){
        assert(sieveCalculated)
        mobius = IntArray(sieveMx + 1)
        mobius[1] = 1
        for(i in 2..sieveMx){
            val p = primeOf[i]
            if(p == primeOf[i/p]){
                mobius[i] = 0
            }else{
                mobius[i] = -1 * mobius[i/p]
            }
        }
    }
    fun primesUpto(x:Int):IntArray{
        val ret = mutableListOf<Int>()
        for(i in 2..x){
            if(primeOf[i] == i){
                ret.add(i)
            }
        }
        return ret.toIntArray()
    }
    operator fun contains(v:Int):Boolean = this.primeOf[v] == v
}
inline fun Int.eachPrimePower(act:(p:Int,e:Int)->Unit){
    assert(sieve.sieveCalculated)
    var here = this
    while(here > 1){
        act(sieve.nextPrime[here], sieve.nextPrimePower[here])
        here = sieve.afterPrimePowerDivison[here]
    }
}
fun Int.factors():List<Int>{
    val ret = mutableListOf(1)
    this.eachPrimePower { p, e ->
        val s = ret.toList()
        var now = 1
        repeat(e){
            now *= p
            ret.addAll(s.map{it * now})
        }
    }
    return ret
}
fun totient(a:Int):Int{
    var ret = a
    a.eachPrimePower{
            p, _ ->
        ret /= p
        ret *= (p-1)
    }
    return ret
}
fun Int.numOfDivisors():Int{
    var ret = 1
    this.eachPrimePower { _, e -> ret *= (e+1) }
    return ret
}
inline fun Int.eachFactor(act:(Int)->Unit){
    val end = if(this == sieve.sieveMx) sieve.factor.lastIndex else (sieve.fstart[this+1]-1)
    for(i in sieve.fstart[this]..end){
        act(sieve.factor[i])
    }
}
fun Int.factorLook():IntArray{
    val end = if(this == sieve.sieveMx) sieve.factor.lastIndex else (sieve.fstart[this+1]-1)
    return sieve.factor.sliceArray(sieve.fstart[this]..end)
}

const val p = 1_000_000_007
const val singleCase = false
fun main(){
    sieve.calculateSieveFast()
    sieve.preparePrimePower()
    sieve.prepareFactor()
    solve.cases{

        val n = getint
        val q = getint
        val A = intArrayOf(0) +  getline(n)

        val arr = Array(n+1){
            multiset()
        }
        for(t in 1..n){
            for(i in t..n step t){
                arr[t].addone(A[i])
            }
        }
        fun make(i:Int):item{
            if(i == 0){
                return merge.construct(0,0, arr[i+1].first(), arr[i+1].last())
            }else{
                return merge.construct(arr[i].first(), arr[i].last(), arr[i+1].first(), arr[i+1].last())
            }
        }
        val start = Array(n){
            make(it)
        }

        val st = gSeg(start)

        repeat(q){
            val i = getint
            val x= getint
            val changed = TreeSet<Int>()

            val old = A[i]
            i.eachFactor {  t ->
                arr[t].removeone(old)
                arr[t].addone(x)
                changed.add(t-1)
                if(t < n) changed.add(t)
            } // flip 1
            A[i] = x
            for(a in changed){
                st.set(a, make(a))
            }
            val final = st.arr[1]
            put(maxOf(final.w00, final.w01))

        }







    }
    done()
}
