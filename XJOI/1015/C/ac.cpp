#include<bits/stdc++.h>

using namespace std;

const long long ANS[500]={4470510ll,172661042827ll,30877202955ll,12591024446ll,110016023855ll,234669318ll,4365515ll,79893138ll,64869681965ll,3758963838ll,53123147935ll,97440153062ll,65436086469ll,19202359715ll,7702420146ll,82310655427ll,327875685ll,333893405846ll,765467165355ll,789695888366ll,32626469343ll,24375171170ll,4148531140611ll,11057949574ll,3148192661055ll,13382128298ll,1545870027ll,252066726010ll,302737071ll,117902178295ll,15519748426ll,39308375055ll,997349353ll,1150559037770ll,6329323255827ll,207402478430ll,5047159080381ll,41952759394ll,1435914265ll,872913657ll,5040486230ll,8116239747ll,369127700890ll,996382120503ll,381797869765ll,3765704688262ll,25834999827ll,28257480530ll,35439917799ll,2145883354762ll,628135803555ll,11160165478ll,135176160535ll,505466647158ll,21349285685ll,56290257914ll,26538248950707ll,1494176530ll,1431408381ll,77035310ll,30177717297ll,1022990286190ll,40457079201ll,5779015190ll,395779293679ll,654498582438ll,62592580505ll,1903931898ll,229364676359ll,2794327910ll,206767171299ll,11767910ll,9217495233843ll,70878962495ll,102562063422ll,554822157109ll,23943357901255ll,17859534ll,73374858635ll,27560032269ll,2479432179614ll,158581862915ll,4011317178ll,21547065995ll,44154066ll,2729682215ll,5969405211ll,189817030ll,18111289119ll,3540722770ll,3011413436241ll,4668180110ll,16128810789ll,38887590890ll,10087249557ll,38122589102ll,21819936985ll,522705514146ll,123353643985ll,1930338192202ll,126513915ll,892789534ll,788150913ll,605943583570ll,1155347319749ll,53860314651ll,960325761470ll,17300158239ll,104034258217571ll,436457726810ll,1945174101ll,10500709670ll,20450933139ll,5430035270ll,109413375351ll,182926310397142ll,20622044905ll,6501802242ll,699498415ll,60962462366ll,7624313445ll,22327239374ll,2305024995ll,29466228418ll,15294436365ll,11169622280971ll,768900626ll,91261695ll,34482235766ll,1189657335165ll,5742324742ll,33429203835ll,368453836933ll,26554452819114ll,17626835135ll,4135792752278ll,551546079ll,483340390ll,29910276561ll,12856854374ll,438567105ll,17749746322ll,5815677233379ll,2789120530ll,21444213219ll,3753922690ll,48142093467ll,152126579990ll,2101308477ll,324617632430ll,3651940251597ll,12269228270ll,15741890241ll,9395608790ll,23470700253ll,4703077030ll,1187554654429ll,6711185985ll,2475536763778ll,206717699265ll,24873188002ll,305973255ll,347622345499ll,16066749130ll,39664637103ll,268528634ll,40453983115ll,7287142038ll,90288725135ll,39286421031ll,5715040133354ll,37135333235ll,503857056018ll,36646242815ll,4527222319862ll,58882615665ll,9432736586ll,133700902115ll,62660321607ll,170164784510ll,229754512559ll,3320668722ll,24967594432055ll,199450342ll,873769245ll,833743310686ll,6213150195ll,1548275702828569ll,120120903770ll,104006518473ll,27425062966ll,894761624045ll,17967027507ll,3452130710ll,213683327143ll,51689310ll,42091362313ll,23614567905ll,7652974966ll,915996660315ll,53285620726ll,185503726177ll,24234690ll,23564153503163ll,4215754424409ll,5566161230ll,7158322712931ll,10735539181829ll,10068846190ll,26655930609ll,793380055ll,2258625138ll,103627121ll,5300794470ll,31474490047ll,3412551810ll,138080116889ll,25384174305ll,776945728702ll,59281371177ll,3800808739585ll,188084838ll,60116934605ll,3786587574418ll,5208863094591ll,13473334105ll,458169644946ll,311846442103ll,68850629705ll,20579622ll,76645040615ll,21670606071149ll,15014630922330ll,84137026127ll,11897482090ll,48562819701ll,12940236218ll,11049254205ll,8707998026ll,708896888205ll,9732468382ll,40851685083ll,23533427645ll,4806080598ll,2759091517ll,285841545ll,3081385762ll,207997364245ll,25954749303ll,12587717090ll,162917800881ll,568275439459ll,4785998470ll,305818557963ll,11395133386ll,71102262935ll,20585099406ll,173928755ll,241478447758ll,22968539139ll,112766693215ll,4210921974ll,148948519915ll,10570695982ll,16422953235ll,5924875097911ll,1560927810ll,264175442377ll,13699486210ll,1640437242717ll,67996230335ll,2913932238ll,52462936955ll,20947192086ll,202016180597ll,664732384810ll,10379088951ll,73020610ll,22333347267ll,55281213598ll,1155705328085ll,2505375561ll,4016200430ll,1360238872083ll,17709881530ll,62871627ll,9780083830ll,99693443213ll,13918860318ll,6654104665ll,76531994ll,106908999873ll,32267239235ll,14716218606ll,1138572584435ll,70943280261ll,187926715915114ll,1067643946785ll,364526184673ll,1204044270ll,264863165077ll,329974905ll,26840320738ll,438951219915ll,12287229878ll,870005304285ll,3410464005146ll,7923794688215ll,15045544254ll,5879730369755ll,9973959177ll,430773028730ll,8395016721ll,529151945410ll,450283029ll,4894050590ll,173707250979ll,13484018002ll,185070761205ll,27836612451739ll,4241070835034ll,114299535ll,1524709394ll,57611895ll,18930438982ll,141401053585ll,100640467347ll,42003612233726ll,7508854185ll,210062138ll,10159038015ll,2569626917962ll,1765277394265ll,6460968354ll,39873983695ll,26266682354ll,10196465685ll,289081292929ll,15849370ll,631793051967ll,545769226210ll,3718572280203ll,62154796795ll,103547467262ll,102299281095ll,7721025350311ll,4015700502ll,2370623132605ll,13102276386ll,2083851398629ll,8103417510ll,10049997673639ll,82860467703ll,3678315410ll,1752577062171ll,896773296958ll,1129155820455ll,91727174ll,2233284719205ll,7212381722ll,15681858555ll,220960907531ll,294520069338ll,1335357905ll,1072499636494ll,62030535ll,32261544458ll,26006466249627ll,76505590ll,367793283ll,1220433921890ll,68020524831ll,3088527375505ll,7108507266ll,78946029955ll,20076729981ll,3800914910ll,16318315167ll,301351310ll,185494701ll,1657432205ll,728528709966ll,2951626692245ll,2233942414678ll,8829151611621ll,142970652895ll,884442ll,185494061555ll,98658546ll,6426115894627ll,793557870ll,299798510297ll,6801248055ll,187904286662ll,1573546409435ll,13752293718ll,18030954305ll,158654510454ll,12529985195ll,604784262126ll,59855645185ll,6179249646622ll,245270487ll,4771361270ll,21209442639ll,662809511090ll,1586521937ll,945885390666ll,63215188465ll,14942980654ll,80762391015ll,27950882102ll,4317861745715ll,231157295094ll,1899043836235ll,3125508474ll,359546005ll,1127346ll,405445495ll,54509654078ll,25970788905ll,1340450450794ll,9314010915ll,193245469781ll,255754538710ll,141848889ll,26672723343530ll,60454340961ll,166182876145ll,905314714682ll,362424189621ll,922198915ll,5112697506ll,40058918185ll,159462822ll,634617598615ll,97735278ll,206306037306655ll,71169286251ll,8234567510ll,8019403019661ll,40577810ll,7515076327ll,9840528285ll,355671602ll,13313655915ll,17561072386ll,61662572545ll,5662258988529ll,10033274710ll,561989337ll,1692897910ll,6413383480161ll,280633324829ll,583848727210ll,46810416147ll,78630206122ll,219237865ll,10474522311903ll,691772339690ll,2697452234169ll,2433410936086ll,131094019385ll,11813986041ll,21392951930ll,1219996041ll,146106883715ll,2354127258ll,81693119365ll,448295253ll,685855557530ll,2272770341331ll,4360146230ll,37728054273ll,690074198ll,1520081605ll,6956647393839ll,71545535810ll,958125597ll,431717317015ll,9930425582ll,737500318815ll,30029357842ll,2233422951305ll,2959218042ll,1475046966585985ll,16223539101ll,3326975990ll,68189072469ll,1787990215ll,6992632738ll,225569685ll,4338979562866ll,18868382841ll,7315643530ll,87609533473ll,133876276599ll,52108210ll,785093072361ll,41509930ll};

int n;

int main()
{
	scanf("%d",&n);
	long long mx=0;
	for(int i=0;i<n;++i)
		mx=max(mx,ANS[i]);
	cout<<mx;
	return 0;
}
